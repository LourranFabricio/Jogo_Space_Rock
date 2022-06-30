#include <allegro.h>

class Enemy{
	public:
		int tGame,y;
		
		BITMAP* naveInimiga;
		
		struct Naves{
			int wx, wy, x, y, w, h, t;
		}NaveInimiga[5],Explosao;
		
		void MoverInimigo(Naves *NaveInimiga);
		
		Enemy();
		
		void Controla(int tGame);
	
};

Enemy::Enemy(){
	
	NaveInimiga[0].wx = 237;
	NaveInimiga[0].wy = 250;
	NaveInimiga[0].x = 1280;
	NaveInimiga[0].y = 190;
	NaveInimiga[0].w = 84;
	NaveInimiga[0].h = 76;
	NaveInimiga[0].t = 0;
	
	NaveInimiga[1].wx = 237;
	NaveInimiga[1].wy = 250;
	NaveInimiga[1].x = 1430;
	NaveInimiga[1].y = 310;
	NaveInimiga[1].w = 84;
	NaveInimiga[1].h = 76;
	NaveInimiga[1].t = 1;
	
	NaveInimiga[2].wx = 237;
	NaveInimiga[2].wy = 250;
	NaveInimiga[2].x = 1370;
	NaveInimiga[2].y = 440;
	NaveInimiga[2].w = 84;
	NaveInimiga[2].h = 76;
	NaveInimiga[2].t = 2;
	
	NaveInimiga[3].wx = 237;
	NaveInimiga[3].wy = 250;
	NaveInimiga[3].x = 1590;
	NaveInimiga[3].y = 210;
	NaveInimiga[3].w = 84;
	NaveInimiga[3].h = 76;
	NaveInimiga[3].t = 3;
	
	NaveInimiga[4].wx = 237;
	NaveInimiga[4].wy = 250;
	NaveInimiga[4].x = 1660;
	NaveInimiga[4].y = 430;
	NaveInimiga[4].w = 84;
	NaveInimiga[4].h = 76;
	NaveInimiga[4].t = 4;
	
	Explosao.wx = 237;
	Explosao.wy = 173;
	Explosao.x = -80;
	Explosao.y = 300;
	Explosao.w = 83;
	Explosao.h = 80;
	Explosao.t = 0;
	
	naveInimiga = load_bitmap("inimigos/inimigos.bmp", NULL);
	y = 0;
}

void Enemy::MoverInimigo(Naves *NaveInimiga){
	y++;
	if(NaveInimiga->x > - NaveInimiga->w) NaveInimiga->x -= 4;
	NaveInimiga->t += 1;
	if(NaveInimiga->t > 30) NaveInimiga->t = 0;
	if(y < 499){
		NaveInimiga->t -= 1;
		NaveInimiga->y -= 1;
	}
	else NaveInimiga->y += 1;
	if(y > 1000) y = 0; 

}

void Enemy::Controla(int tGame){
	
	if((tGame > 2 && tGame < 8) || (tGame > 9 && tGame < 15) || (tGame > 16 && tGame < 22) || (tGame > 23 && tGame < 29)){
		for(int i = 0; i < 5; i++) MoverInimigo(&NaveInimiga[i]);
	}
	else{
		if(NaveInimiga[0].x <= -NaveInimiga[0].w) NaveInimiga[0].x = 1280;
		if(NaveInimiga[1].x <= -NaveInimiga[1].w) NaveInimiga[1].x = 1430;
		if(NaveInimiga[2].x <= -NaveInimiga[2].w) NaveInimiga[2].x = 1370;
		if(NaveInimiga[3].x <= -NaveInimiga[3].w) NaveInimiga[3].x = 1590;
		if(NaveInimiga[4].x <= -NaveInimiga[4].w) NaveInimiga[4].x = 1660;
		
	}
}





