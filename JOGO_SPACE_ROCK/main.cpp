#include <allegro.h>
#include "Cenario.h"
#include "Musica.h"
#include "Colisao.h"

void init();
void deinit();



int width = 1280;
int height = 720;
int v = 1;
int test = 0;
float tGame = 0;
int tgame;

BITMAP *buffer,*imagem;
SAMPLE *som;
FONT *font32;

void Tempo();
void menu();


class Stars{

	private:
		int x[200];
		int y[200];
		int w[200];
		int i;

	public:
		Stars(){
			for(i=0;i<200;i++){
				x[i] = 0;
				y[i] = 0;
				w[i] = 2;
			}
		
		}

		void CriaEstrelas(){
			for(i=0;i<200;i++){
				if(x[i]-- < 0){
					x[i] = (rand()%1280 + 1280);
					y[i] = rand()%720;
					w[i] = rand()%2;
				}
				if(i%2)x[i]--;
				circlefill(buffer, x[i], y[i], w[i], 0xffffff);

			}
		}


};



int main() {
	init();
	
	//
	FONT *font_vida;
	FONT *font_score;
	font_vida = load_font("fontes/digital.pcx",NULL,NULL);
	font_score = load_font("fontes/digital.pcx",NULL,NULL);
	font32 = load_font("fontes/digital.pcx",NULL,NULL);
	imagem = load_bitmap("menu/menu.bmp",NULL);
	som = load_sample("menu/musica.wav");
	//
	
	//Cores da barra de energia
	int tCor[5] = {0xF860FF, 0XF86000,0X0070D8, 0XBBBB9B2, 0XFFFFEE};
	//Cores da barra de energia
	
	//Objetos
	
	//Objeto Jogador
	Player Nave(2,0,100,100,150,200);
	//Objeto Jogador
	
	//Objeto Inimigo
	Enemy Inimigo;
	//Objeto Inimigo
	Colisao Acao;
	//Objeto Radio
	Radio Musica;
	//Objeto Radio
	
	
	//Objeto Cenario
	Stars Estrela;
	
	PlanetaTerra Terra(0,0,930,550,451,450);
	
	PlanetaMarte Marte(0,0,100,8,101,101);
	
	PlanetaSaturno Saturno(0,0,700,90,271,271);
	
	PlanetaJupiter Jupiter(0,0,-200,300,300,300);
	
	Galaxia Glaxia(0,0,1100,10,75,75);
	
	EstrelaSol Sol(0,0,430,90,90,90);
	//Objeto Cenario
	
	//Objetos
	

	//Instala a parte de som do jogo
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
	//Instala a parte de som do jogo
	
	//Buffer que armazena as imagens
	buffer = create_bitmap(width,height);
	//Buffer que armazena as imagens
	 
	menu();
	while(v==1 && (!key[KEY_ESC])){
		/* put your code here */
		Tempo();
		for(int i=0;i<10;i++){
			for(int j=0;j<5;j++){
				if((Acao.Colide(&Nave.vetTiros[i],&Inimigo.NaveInimiga[j],Nave.tiros,Inimigo.naveInimiga))|| 
				(i<3 && (Acao.Colide(&Nave.plasma[i],&Inimigo.NaveInimiga[j],Nave.tiros,Inimigo.naveInimiga)))){
					
					play_sample(Nave.hit, 255,128,1000,0);
					Inimigo.Explosao.t = 0;
					Nave.vetTiros[i].x = Nave.out;
					Inimigo.Explosao.x = Inimigo.NaveInimiga[j].x;
					Inimigo.Explosao.y = Inimigo.NaveInimiga[j].y;
					Inimigo.NaveInimiga[j].x = -100;
					Nave.SetPoints(Nave.GetPoints()+120);
				}
			}
		}
		if(Inimigo.Explosao.t < 40) Inimigo.Explosao.t++;
			
		for(int i=0;i<5;i++){
			if((Acao.Colide2(Nave.wx,Nave.wy,Nave.GetPosx(),Nave.GetPosy(),Nave.w,Nave.h,&Inimigo.NaveInimiga[i],Nave.espaconave,Inimigo.naveInimiga)&& Inimigo.NaveInimiga[i].x < width)){
				
				Nave.SetVida(Nave.GetVida()-1);
				Inimigo.Explosao.t = 0;
				Inimigo.NaveInimiga[i].x = - Inimigo.NaveInimiga[i].w;
				if(Nave.GetVida() == 0){
						
					v = 0;
					Inimigo.Explosao.x = Nave.GetPosx();
					Inimigo.Explosao.y = Nave.GetPosy();
					Nave.SetPosx(-width);	
					}
				}
			}
			
		//Cenario
		//CriaEstrelas
		Estrela.CriaEstrelas();
		//CriaEstrelas
			
		//Planeta terra
		Terra.Animacao(Terra.fr,Terra.v);
		masked_blit(Terra.planeta_terra, buffer,Terra.wx + (Terra.fr/10)*Terra.w, Terra.wy,Terra.x,Terra.y,Terra.w,Terra.h);
		if((Terra.wx + (Terra.fr/10)*Terra.w)>3000) Terra.fr = 0;
		//Planeta terra
			
		//Planeta marte
		Marte.Animacao(Marte.fr,Marte.v);
		masked_blit(Marte.planeta_marte, buffer,Marte.wx + (Marte.fr/10)*Marte.w, Marte.wy,Marte.x,Marte.y,Marte.w,Marte.h);
		if((Marte.wx + (Marte.fr/10)*Marte.w)>2000) Marte.fr = 0;
		//Planeta marte
			
		//Planeta saturno
		Saturno.Animacao(Saturno.fr,Saturno.v);
		masked_blit(Saturno.planeta_saturno, buffer,Saturno.wx + (Saturno.fr/10)*Saturno.w,Saturno.wy,Saturno.x,Saturno.y,Saturno.w,Saturno.h);
		if((Saturno.wx + (Saturno.fr/10)*Saturno.w)>2000) Saturno.fr = 0;
		//Planeta saturno
			
		//Planeta jupiter
		Jupiter.Animacao(Jupiter.fr,Jupiter.v);
		masked_blit(Jupiter.jupiter, buffer,Jupiter.wx + (Jupiter.fr/10)*Jupiter.w,Jupiter.wy,Jupiter.x,Jupiter.y,Jupiter.w,Jupiter.h);
		if((Jupiter.wx + (Jupiter.fr/10)*Jupiter.w)>2500) Jupiter.fr = 0;
		//Planeta jupiter
			
		//Galaxia
		Glaxia.Animacao(Glaxia.fr,Glaxia.v);
		masked_blit(Glaxia.galaxy,buffer,Glaxia.wx + (Glaxia.fr/10)*Glaxia.w,Glaxia.wy,Glaxia.x,Glaxia.y,Glaxia.w,Glaxia.h);
		if((Glaxia.wx + (Glaxia.fr/10)*Glaxia.w)>3500) Glaxia.fr = 0;
		//Galaxia
			
		//Sol
		Sol.Animacao(Sol.fr,Sol.v);
		masked_blit(Sol.estrela,buffer,Sol.wx + (Sol.fr/10)*Sol.w,Sol.wy,Sol.x,Sol.y,Sol.w,Sol.h);
		if((Sol.wx + (Sol.fr/10)*Sol.w)>2500) Sol.fr = 0;
		//Sol
		//Cenario
			
			
			
		//Essa função é resposável por fazer a nave voar pela tela e fazer os disparos
		Nave.ControlaNave();
		//Essa função é resposável por fazer a nave voar pela tela e fazer os disparos
			
			
		//Essa função é responsável pela escolha das musicas
		Musica.EscolheMusica();
		//Essa função é responsável pela escolha das musicas
			
			
		//Desenha nave inimiga e controla o movimento
		Inimigo.Controla(tgame);
		for(int i = 0; i <5; i++){
			masked_blit(Inimigo.naveInimiga, buffer, Inimigo.NaveInimiga[i].wx + (Inimigo.NaveInimiga[i].t/11)*Inimigo.NaveInimiga[i].w, Inimigo.NaveInimiga[i].wy,Inimigo.NaveInimiga[i].x,Inimigo.NaveInimiga[i].y,Inimigo.NaveInimiga[i].w,Inimigo.NaveInimiga[i].h);
		}
		if(tGame > 23 && tGame < 29) tGame = 0;
		//Desenha nave inimiga e controla o movimento
			
		//Desenha a nave na tela e atualiza os valores da posição da nave
		Nave.AnimacaoNave();
		masked_blit(Nave.espaconave, buffer,Nave.wx + (Nave.frames/12)*Nave.w, Nave.wy,Nave.GetPosx(),Nave.GetPosy(),Nave.w,Nave.h);
		if((Nave.wx + (Nave.frames/12)*Nave.w)>302) Nave.frames = 0;
		//Desenha a nave na tela e atualiza os valores da posição da nave
			
		//Animacao tiro
		masked_blit(Nave.tiros,buffer,(Nave.tAnime/5)*17+89,0,Nave.GetPosx()+145,Nave.GetPosy()+120,17,32);
		masked_blit(Nave.tiros,buffer,Nave.plasma[t_Type].wx,Nave.plasma[t_Type].wy,Nave.plasma[t_Type].x,Nave.plasma[t_Type].y,Nave.plasma[t_Type].w,Nave.plasma[t_Type].h);
			
		for(int i=0;i<10;i++){
			masked_blit(Nave.tiros,buffer,Nave.vetTiros[i].wx,Nave.vetTiros[i].wy,Nave.vetTiros[i].x,Nave.vetTiros[i].y,Nave.vetTiros[i].w,Nave.vetTiros[i].h);
		}
		//Animacao tiro
			
		masked_blit(Inimigo.naveInimiga, buffer,Inimigo.Explosao.wx + (Inimigo.Explosao.t/11)*Inimigo.Explosao.w,Inimigo.Explosao.wy,Inimigo.Explosao.x,Inimigo.Explosao.y,Inimigo.Explosao.w,Inimigo.Explosao.h);
			
			
		//painel
		textprintf_ex(buffer,font_vida,20,640,0xffffff, -1, "vidas %i", Nave.GetVida());
		textprintf_ex(buffer,font_score,600,640,0xffffff, -1, "score %i", Nave.GetPoints());
		rectfill(buffer,300,655,300 + Nave.pTiro ,680, tCor[t_Type+1 + (blinkTiro/17)]);
		rectfill(buffer,300,658,300 + Nave.pTiro ,665, tCor[4]);
			
		draw_sprite(buffer, Nave.barraDeEnergia,290,650);
		//painel
			
		draw_sprite(screen, buffer, 0, 0);
		rest(5);
		clear(buffer);
}
	


	destroy_bitmap(buffer);

	destroy_bitmap(Nave.espaconave);
	
	destroy_bitmap(Nave.barraDeEnergia);
	
	destroy_bitmap(Nave.tiros);
	
	destroy_font(font_vida);
	
	destroy_font(font_score);
	
	destroy_bitmap(Terra.planeta_terra);
	
	destroy_bitmap(Marte.planeta_marte);
	
	destroy_bitmap(Saturno.planeta_saturno);
	
	destroy_bitmap(Glaxia.galaxy);
	
	destroy_bitmap(Jupiter.jupiter);
	
	destroy_bitmap(Sol.estrela);
	
	
	destroy_sample(som);
	destroy_sample(Musica.padrao);
	
	destroy_sample(Musica.wave0);
	
	destroy_sample(Musica.wave1);
	
	destroy_sample(Musica.wave2);
	
	destroy_sample(Musica.wave3);
	
	destroy_sample(Musica.wave4);
	
	destroy_sample(Musica.wave5);
	
	destroy_sample(Musica.wave6);
	
	destroy_sample(Musica.wave7);
	
	destroy_sample(Musica.wave8);
	
	destroy_sample(Musica.wave9);
	
	destroy_sample(Nave.carga);
	
	destroy_sample(Nave.intro);
	
	destroy_sample(Nave.sMorto);
	
	destroy_sample(Nave.p0);
	
	destroy_sample(Nave.p1);
	
	destroy_sample(Nave.p2);
	
	destroy_sample(Nave.p3);

	deinit();
	return 0;
}
END_OF_MAIN()
//------------------------------------------------------------------------------------------------------
void Tempo(){
	tGame += 0.01;
	tgame = tGame;
}
//------------------------------------------------------------------------------------------------------
void menu(){
	int time = 0, flash = 0;
	
	play_sample(som,255,128,1000,1);
	
	while(!key[KEY_SPACE]){
		
		if(time>50) time = 0;
		
		draw_sprite(buffer, imagem, 0,0);
		if(time<30)
		textprintf_centre_ex(buffer,font32,width/2,height/1.2,0xffffff,-1,"PRESS START");
		draw_sprite(screen, buffer, 0, 0);
		rest(10);
		clear(buffer);
		time+=2;
	}
	stop_sample(som);
	rest(500);
	
}
//------------------------------------------------------------------------------------------------------
void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1280, 720, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
