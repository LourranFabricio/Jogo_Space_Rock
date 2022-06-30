#include <allegro.h>

class Radio{
	
	public:
		Radio();
		void EscolheMusica();
		SAMPLE *wave0, *wave1, *wave2,*wave3, *wave4, *wave5, *wave6, *wave7, *wave8, *wave9, *padrao;
		int valida;
		
		
	
	
};

Radio::Radio(){
	
	padrao = load_sample("musicas/crazy.wav");
	wave0 = load_sample("musicas/Star_Wars.wav");
	wave1 = load_sample("musicas/byob.wav");
	wave2 = load_sample("musicas/crawling.wav");
	wave3 = load_sample("musicas/dont.wav");
	wave4 = load_sample("musicas/feel.wav");
	wave5 = load_sample("musicas/highway.wav");
	wave6 = load_sample("musicas/immortals.wav");
	wave7 = load_sample("musicas/paranoid.wav");
	wave8 = load_sample("musicas/pinkfloid.wav");
	wave9 = load_sample("musicas/working.wav");
	valida = 0;
	
	
}

void Radio::EscolheMusica(){
	
	if(!key[KEY_1] && !key[KEY_2] && !key[KEY_3] && !key[KEY_4] && !key[KEY_5] && !key[KEY_6] && !key[KEY_7] && !key[KEY_8] && !key[KEY_9] && !key[KEY_0] && !valida){
		play_sample(padrao,30,128,1000,1);
		valida =1;
	}
	
	else if(key[KEY_1]){
		stop_sample(padrao);
		stop_sample(wave2);
		stop_sample(wave3);
		stop_sample(wave4);
		stop_sample(wave5);
		stop_sample(wave6);
		stop_sample(wave7);
		stop_sample(wave8);
		stop_sample(wave9);
		stop_sample(wave0);
		
		play_sample(wave1,30,128,1000,0);
	}
	
	else if(key[KEY_2]){
		stop_sample(padrao);
		stop_sample(wave1);
		stop_sample(wave3);
		stop_sample(wave4);
		stop_sample(wave5);
		stop_sample(wave6);
		stop_sample(wave7);
		stop_sample(wave8);
		stop_sample(wave9);
		stop_sample(wave0);
		
		play_sample(wave2,30,128,1000,0);
	}
	else if(key[KEY_3]){
		stop_sample(padrao);
		stop_sample(wave2);
		stop_sample(wave1);
		stop_sample(wave4);
		stop_sample(wave5);
		stop_sample(wave6);
		stop_sample(wave7);
		stop_sample(wave8);
		stop_sample(wave9);
		stop_sample(wave0);
		
		play_sample(wave3,30,128,1000,0);
	}
	else if(key[KEY_4]){
		stop_sample(padrao);
		stop_sample(wave2);
		stop_sample(wave3);
		stop_sample(wave1);
		stop_sample(wave5);
		stop_sample(wave6);
		stop_sample(wave7);
		stop_sample(wave8);
		stop_sample(wave9);
		stop_sample(wave0);
		
		play_sample(wave4,30,128,1000,0);
	}
	else if(key[KEY_5]){
		stop_sample(padrao);
		stop_sample(wave2);
		stop_sample(wave3);
		stop_sample(wave4);
		stop_sample(wave1);
		stop_sample(wave6);
		stop_sample(wave7);
		stop_sample(wave8);
		stop_sample(wave9);
		stop_sample(wave0);
		
		play_sample(wave5,30,128,1000,0);
	}
	else if(key[KEY_6]){
		stop_sample(padrao);
		stop_sample(wave2);
		stop_sample(wave3);
		stop_sample(wave4);
		stop_sample(wave5);
		stop_sample(wave1);
		stop_sample(wave7);
		stop_sample(wave8);
		stop_sample(wave9);
		stop_sample(wave0);
		
		play_sample(wave6,30,128,1000,0);
	}
	
	else if(key[KEY_7]){
		stop_sample(padrao);
		stop_sample(wave2);
		stop_sample(wave3);
		stop_sample(wave4);
		stop_sample(wave5);
		stop_sample(wave1);
		stop_sample(wave6);
		stop_sample(wave8);
		stop_sample(wave9);
		stop_sample(wave0);
		
		play_sample(wave7,30,128,1000,0);
	}
	else if(key[KEY_8]){
		stop_sample(padrao);
		stop_sample(wave2);
		stop_sample(wave3);
		stop_sample(wave4);
		stop_sample(wave5);
		stop_sample(wave1);
		stop_sample(wave6);
		stop_sample(wave7);
		stop_sample(wave9);
		stop_sample(wave0);
		
		play_sample(wave8,30,128,1000,0);
	}
	else if(key[KEY_9]){
		stop_sample(padrao);
		stop_sample(wave2);
		stop_sample(wave3);
		stop_sample(wave4);
		stop_sample(wave5);
		stop_sample(wave1);
		stop_sample(wave6);
		stop_sample(wave7);
		stop_sample(wave8);
		stop_sample(wave0);
		
		play_sample(wave9,30,128,1000,0);
	}
	else if(key[KEY_0]){
		stop_sample(padrao);
		stop_sample(wave2);
		stop_sample(wave3);
		stop_sample(wave4);
		stop_sample(wave5);
		stop_sample(wave1);
		stop_sample(wave6);
		stop_sample(wave7);
		stop_sample(wave8);
		stop_sample(wave9);
		
		play_sample(wave0,50,128,1000,0);
	}
	
}

