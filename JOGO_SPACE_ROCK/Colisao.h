#include <allegro.h>
#include "Player.h"
#include "Enemy.h"

class Colisao: public Player,Enemy{
	
	public:
		struct Geral{
			int wx, wy, x, y, w, h, t;
		};
		Colisao();
	public: 
		int Colide(struct tirosNave *A,struct Naves *B, BITMAP *imgA, BITMAP *imgB);
		int Colide2(int wx, int wy, int posx, int posy, int w, int h,struct Naves *B, BITMAP *imgA, BITMAP *imgB);
		

};

Colisao::Colisao(){
}

int Colisao::Colide(struct tirosNave *A, struct Naves *B, BITMAP *imgA, BITMAP *imgB){
	int awx = A->wx , awy = A->wy, ax = A->x, ay = A->y, aw = A->w, ah = A->h;
	int bwx = B->wx , bwy = B->wy, bx = B->x, by = B->y, bw = B->w, bh = B->h;
	
	if(imgA != imgB){awx = 0; awy = 0; bwx = 0; bwy = 0;}
	
	if(ax+aw > bx && ax < bx+bw && ay+ah > by && ay < by+bh){
		int cx, cy, cw, ch, iax, iay, ibx, iby, i , j;
		
		if(ax > bx){
			if(ax+aw < bx+bw) cw = aw;
			else cw = bw-(ax-bx);
			iax = 0;
			ibx = bw-cw;
		}else{
			if(ax+aw > bx+bw) cw = bw;
			else cw  = aw-(bx-ax);
			ibx = 0;
			iax = aw-cw;	
		}
		if(ay > by){
			if(ay+ah < by+bh) ch = ah;
			else ch  = bh-(ay-by);
			iay = 0;
			iby = bh-ch;
		}else{
			if(ay+ah > by+bh) ch = bh;
			else ch = ah-(by-ay);
			iby = 0;
			iay = ah-ch;	
		}
		for(i = 0; i < cw; i++){
			for(j = 0; j < ch; j++){
				if(getpixel(imgA, i + awx + iax, j + awy + iay) != 0xff00ff &&
				   getpixel(imgB, i + bwx + ibx, j + bwy + iby) != 0xff00ff )
				return 1;  
			}
		}		
	}

	return 0;		
}


int Colisao::Colide2(int _wx, int _wy, int _x, int _y, int _w, int _h,struct Naves *B, BITMAP *imgA, BITMAP *imgB){
	int awx = _wx , awy = _wy, ax = _x, ay = _y, aw = _w, ah = _h;
	int bwx = B->wx , bwy = B->wy, bx = B->x, by = B->y, bw = B->w, bh = B->h;
	
	if(imgA != imgB){awx = 0; awy = 0; bwx = 0; bwy = 0;}
	
	if(ax+aw > bx && ax < bx+bw && ay+ah > by && ay < by+bh){
		int cx, cy, cw, ch, iax, iay, ibx, iby, i , j;
		
		if(ax > bx){
			if(ax+aw < bx+bw) cw = aw;
			else cw = bw-(ax-bx);
			iax = 0;
			ibx = bw-cw;
		}else{
			if(ax+aw > bx+bw) cw = bw;
			else cw  = aw-(bx-ax);
			ibx = 0;
			iax = aw-cw;	
		}
		if(ay > by){
			if(ay+ah < by+bh) ch = ah;
			else ch  = bh-(ay-by);
			iay = 0;
			iby = bh-ch;
		}else{
			if(ay+ah > by+bh) ch = bh;
			else ch = ah-(by-ay);
			iby = 0;
			iay = ah-ch;	
		}
		for(i = 0; i < cw; i++){
			for(j = 0; j < ch; j++){
				if(getpixel(imgA, i + awx + iax, j + awy + iay) != 0xff00ff &&
				   getpixel(imgB, i + bwx + ibx, j + bwy + iby) != 0xff00ff )
				return 1;  
			}
		}		
	}
	return 0;		
}



