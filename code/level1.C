#include "level1.h"
#include "image_library.h"
#include "world.h"
namespace csis3700 {

	void level1::populate(world &w){
		w.set_bg(image_library::get_instance()->get("background1.jpg"));
		w.set_player_cords(50,650);
		//bot blocks
		for(int i=0; i<70;i++){
			os=new obstruction_sprite(i*40,700,image_library::get_instance()->get("block.png"));
			w.add_sprite(os);
		}
		//left side blocks
		for(int i=0;i<15;i++){
			os=new obstruction_sprite(0,i*100,image_library::get_instance()->get("block.png"));
			w.add_sprite(os);
		}
		os=new obstruction_sprite(200,650,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(250,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(300,550,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(300,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(350,500,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(350,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(400,500,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(400,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(450,500,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(450,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(500,500,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(500,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(850,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(900,500,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(900,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(950,500,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(950,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1000,500,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1000,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1050,500,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1050,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1100,550,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1100,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1150,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1200,650,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1500,650,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1550,600,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1600,550,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1650,500,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1700,450,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1750,400,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1800,350,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1850,300,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1900,250,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(1950,200,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
		os=new obstruction_sprite(2000,150,image_library::get_instance()->get("block.png"));
		w.add_sprite(os);
	}


}
