#include <allegro.h>

int t_Type;
int blinkTiro;

class Player{
	
	private:
		int posx;
		int posy;
		int vida;
		int points;
		//disparo comum
		int press;
		int atirou;
		//disparo comum
		
	
	
	public:
		BITMAP* espaconave;
		BITMAP*	barraDeEnergia;
		BITMAP*	tiros;
		SAMPLE *carga,*intro,*p0, *p1, *p2, *p3, *sMorto, *hit;
		int wx, wy, x, y, w, h;
		
		struct tirosNave{
			int wx, wy, x, y, w, h, t;
		};
		tirosNave vetTiros[10];
		tirosNave plasma[3];
							   					   
		int out, pTiro, sTiro, tAnime;
		
		int frames;
		
		Player(int wx, int wy, int x, int y, int w, int h);
		Player();
		
		void ControlaNave();
		
		void SetPosx(int posx);
		
		void SetPosy(int posy);
		
		void SetVida(int vida);
		
		void SetPoints(int points);
		
		
		int GetPosx();
		
		int GetPosy();
		
		int GetVida();
		
		int GetPoints();
		
		void AnimacaoNave();
		
	
};

Player::Player(){
}

Player::Player(int wx, int wy, int x, int y, int w, int h){

	vida = 3;
	posx = 100;
	posy = 100;
	points = 0;			
	this->wx = wx;
	this->wy = wy;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	frames = 0;
	
	//imagens		
	espaconave = load_bitmap("nave/nave.bmp",NULL);
	barraDeEnergia = load_bitmap("nave/barra_de_energia.bmp", NULL);
	tiros = load_bitmap("nave/disparos.bmp", NULL);
	
	//Sons
	carga = load_sample("sons/carga.wav");
	sMorto = load_sample("sons/morto.wav");
	intro = load_sample("sons/intro.wav");
	p0 = load_sample("sons/p0.wav");
	p1 = load_sample("sons/p1.wav");
	p2 = load_sample("sons/p2.wav");
	p3 = load_sample("sons/p3.wav");
	hit = load_sample("sons/hit.wav");		
	for(int i=0;i<10;i++){
		vetTiros[i].wx = 0;
		vetTiros[i].wy = 182;
		vetTiros[i].x = 1500;
		vetTiros[i].y = 200;
		vetTiros[i].w = 18;
		vetTiros[i].h = 18;
	}
		
	plasma[0].wx = 20;
	plasma[0].wy = 182;
	plasma[0].x = 1500;
	plasma[0].y = 0;
	plasma[0].w = 44;
	plasma[0].h = 19;
	plasma[0].t = 0;
			
	plasma[1].wx = 66;
	plasma[1].wy = 172;
	plasma[1].x = 1500;
	plasma[1].y = 0;
	plasma[1].w = 35;
	plasma[1].h = 41;
	plasma[1].t = 0;
			
	plasma[2].wx = 104;
	plasma[2].wy = 145;
	plasma[2].x = 1500;
	plasma[2].y = 0;
	plasma[2].w = 73;
	plasma[2].h = 91;
	plasma[2].t = 0;
			

	press = 0;
	atirou = 0;
	out = 1500;
	t_Type = 0;
	pTiro = 0;
	sTiro = 0;
	tAnime = 0;
}

void Player::ControlaNave(){
			
	if(key[KEY_D] && posx < 1100){
		
		if(posx <150) posx+=6;
		else posx+=9;
		SetPosx(posx);
		
	}
			
	if(key[KEY_A] && posx > 5) 
	{ 
		if(posx <150) posx+=-6;
		else posx+=-9;
		SetPosx(posx);
	
		 
	}
	
	if(key[KEY_W] && posy > -100 ){
		
		if(posx <150) posy+=-6;
		else posy+=-9;
		SetPosy(posy);
			
	} 
	
	if(key[KEY_S] && posy < 450 ){
		
		if(posx<150) posy+=6;
		else posy+=9;
		SetPosy(posy);
		
	}
	
	//Disparo normal
	if(key[KEY_SPACE] && !press){
		
		press = 1;
		atirou = 1;
		play_sample(p0,255,128,1000,0);
		
	}
	
	if(!key[KEY_SPACE] ){
		
		press = 0;
		pTiro = 0;
		tAnime = 19;
		stop_sample(carga);
	}
	
	
	for(int i=0;i<10;i++){
		
		if(vetTiros[i].x > 1280 && atirou){
			vetTiros[i].x = posx + 130;
			vetTiros[i].y = posy +135 - vetTiros[i].h/2;
			atirou = 0;
		}
		
		if(vetTiros[i].x <= 1280 ){
			vetTiros[i].x += 15;
		}
		
	}
	//Disparo normal
	
	
	//Disparo de plasma
	if(!key[KEY_SPACE] && sTiro && plasma[t_Type].x >= out){
		plasma[t_Type].x = posx +130;
		plasma[t_Type].y = posy +135 - plasma[t_Type].h/2;
		pTiro = 0;
		tAnime = 19;
		sTiro = 0;
		if(t_Type == 0) play_sample(p1,255,128,1000,0);
		if(t_Type == 1) play_sample(p2,255,128,1000,0);
		if(t_Type == 2) play_sample(p3,255,128,1000,0);
	}
	
	if(plasma[t_Type].x < out) plasma[t_Type].x += 15;
	if(plasma[t_Type].x >= out && !sTiro) t_Type = 0;
	
	//Carregar barra de energia
	if(key[KEY_SPACE]){
		if(tAnime++ > 10) tAnime = 0;
		if(pTiro < 200) pTiro+=2;
		if(pTiro == 10) play_sample(carga,255,128,1000,0);
		if(pTiro > 10 && !t_Type) sTiro = 1;
		if(sTiro == 1 && pTiro == 200){ //Reinicia a barra
			
			pTiro = 0;
			sTiro = 2;
			t_Type = 1;
		}
		if(sTiro == 2 && pTiro == 200) t_Type = 2;
		
	}
	//Barra full
	if(t_Type == 2 && pTiro == 200) blinkTiro++;
	if(blinkTiro > 30 || t_Type < 2) blinkTiro = 0;
	
	
}


void Player::SetPosx(int posx){
	this->posx = posx;
}

void Player::SetPosy(int posy){
	this->posy = posy;
}

void Player::SetVida(int vida){
	this->vida = vida;
}

void Player::SetPoints(int points){
	this->points = points;
}


int Player::GetPosx(){
	return posx;
}
		
int Player::GetPosy(){
	return posy;
}

int Player::GetVida(){
	return vida;
}

int Player::GetPoints(){
	return points;
}


void Player::AnimacaoNave(){
			
	if(frames<302)frames++;
			
}


