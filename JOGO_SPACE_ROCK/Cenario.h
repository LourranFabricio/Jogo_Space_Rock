#include <allegro.h>

class Controle{
	public: 
		int frames, valor;
		Controle();
		void Animacao(int &frames, int valor){
			if(frames < valor){
				frames++;
			}
		}
	
};

Controle::Controle(){
}

//-----------------------------------------------------------------------------------------------------------------------------------//

class PlanetaTerra: public Controle{
	public:
		int wx, wy, x, y, w, h, dx, dy, ant_wx;
		int fr, v;
		BITMAP *planeta_terra;
		
		PlanetaTerra(int wx, int wy, int x, int y, int w, int h);
	
};

PlanetaTerra::PlanetaTerra(int wx, int wy, int x, int y, int w, int h){
			
	this->wx = wx;
	this->wy = wy;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	planeta_terra = load_bitmap("background/terra.bmp",NULL);
	fr = 0;
	v = 3000;
	
}

//-----------------------------------------------------------------------------------------------------------------------------------//

class PlanetaMarte: public Controle{
	public:
		int wx, wy, x, y, w, h, dx, dy, ant_wx;
		BITMAP *planeta_marte;
		int fr, v;
		
		PlanetaMarte(int wx, int wy, int x, int y, int w, int h);
	
	
		void AnimacaoPlanetaMarte();
		
};

PlanetaMarte::PlanetaMarte(int wx, int wy, int x, int y, int w, int h){
			
	this->wx = wx;
	this->wy = wy;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	
	planeta_marte = load_bitmap("background/marte.bmp",NULL);
	
	fr = 0;
	v = 2000;
	
}

//-----------------------------------------------------------------------------------------------------------------------------------//


class PlanetaSaturno: public Controle{
	public:
		int wx, wy, x, y, w, h, dx, dy, ant_wx;
		int fr, v;
		BITMAP *planeta_saturno;
		
		PlanetaSaturno(int wx, int wy, int x, int y, int w, int h);
	
	
};

PlanetaSaturno::PlanetaSaturno(int wx, int wy, int x, int y, int w, int h){
			
	this->wx = wx;
	this->wy = wy;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	frames = 0;
	planeta_saturno = load_bitmap("background/saturno.bmp",NULL);
	fr = 0;
	fr = 2000;
	
}

//-----------------------------------------------------------------------------------------------------------------------------------//


class Galaxia: public Controle{
	public:
		int wx, wy, x, y, w, h, dx, dy, ant_wx;
		int fr, v;
		BITMAP *galaxy;
		
		Galaxia(int wx, int wy, int x, int y, int w, int h);
	
};

Galaxia::Galaxia(int wx, int wy, int x, int y, int w, int h){
			
	this->wx = wx;
	this->wy = wy;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	frames = 0;
	galaxy = load_bitmap("background/galaxy.bmp",NULL);
	fr = 0;
	v = 3500;
	
}




class EstrelaSol: public Controle{
	public:
		int wx, wy, x, y, w, h, dx, dy, ant_wx;
		int fr, v;
		BITMAP *estrela;
		
		EstrelaSol(int wx, int wy, int x, int y, int w, int h);
	
};

EstrelaSol::EstrelaSol(int wx, int wy, int x, int y, int w, int h){
			
	this->wx = wx;
	this->wy = wy;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	frames = 0;
	estrela = load_bitmap("background/stars.bmp",NULL);
	fr = 0;
	v = 2500;
	
}
	


class PlanetaJupiter: public Controle{
	public:
		int wx, wy, x, y, w, h, dx, dy, ant_wx;
		int fr, v;
		BITMAP *jupiter;
		
		PlanetaJupiter(int wx, int wy, int x, int y, int w, int h);
};

PlanetaJupiter::PlanetaJupiter(int wx, int wy, int x, int y, int w, int h){
			
	this->wx = wx;
	this->wy = wy;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	jupiter = load_bitmap("background/jupiter.bmp",NULL);
	fr = 0;
	v = 2500;
}




