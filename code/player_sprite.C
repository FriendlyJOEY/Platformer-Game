#include "player_sprite.h"
#include "image_library.h"
#include "image_sequence.h"
#include "vec2d.h"
#include "collision.h"
#include <cmath>
using namespace std;

namespace csis3700 {

  player_sprite::player_sprite(float initial_x, float initial_y) :
    phys_sprite(initial_x, initial_y) {
    sequence = new image_sequence();
    sequence->add_image(image_library::get_instance()->get("player.png"),0);

    run_L = new image_sequence();
    run_L->add_image(image_library::get_instance()->get("player.png"),0.25);
    run_L->add_image(image_library::get_instance()->get("player1.png"),0.25);
    run_L->add_image(image_library::get_instance()->get("player2.png"),0.25);
    run_L->add_image(image_library::get_instance()->get("player3.png"),0.25);

    run_R=new image_sequence();
    run_R->add_image(image_library::get_instance()->get("player3.png"),0.25);
    run_R->add_image(image_library::get_instance()->get("player2.png"),0.25);
    run_R->add_image(image_library::get_instance()->get("player1.png"),0.25);
    run_R->add_image(image_library::get_instance()->get("player.png"),0.25);

    st = new image_sequence();
    st->add_image(image_library::get_instance()->get("player.png"),0);
    on_ground=false;
    alive=true;
    kill=false;
  }

  bool player_sprite::is_passive() const {
    return false;
  }

  void player_sprite::set_on_ground(bool v) {
    on_ground = v;
  }

  void player_sprite::advance_by_time(double dt) {
    phys_sprite::advance_by_time(dt);
    //if(on_ground==false){
    	//position+=vec2d(0,1);
    //}
  }

  void player_sprite::draw(){
      if(alive==true)
        sprite::draw();
      else{
          set_position(vec2d(60,650));
          alive=true;
      }
  }

  void player_sprite::resolve(const collision& collision, sprite *other) {
		if(other-> is_passive()==true){
			while(collision.is_active()){
				//Player Y cords
				float lrc_y=this->bounding_box().lower_right_corner().get_y();
				float ulc_y=this->bounding_box().upper_left_corner().get_y();
				float llc_y=ulc_y+this->bounding_box().get_height();
				float urc_y=lrc_y-this->bounding_box().get_height();

				//Player X cords
				float right_x=this->bounding_box().lower_right_corner().get_x();
				float left_x=this->bounding_box().upper_left_corner().get_x();

				if(collision.collision_rectangle().get_width()>collision.collision_rectangle().get_height()){
					//Bottom Collision
					if(collision.collision_rectangle().contains(vec2d(left_x,llc_y)) || collision.collision_rectangle().contains(vec2d(right_x,lrc_y))){
						set_velocity(vec2d(get_velocity().get_x(),0));
						set_position(vec2d(position.get_x(),position.get_y()-collision.collision_rectangle().get_height()-1));
						on_ground=true;
						break;
					}
					else{
						set_velocity(vec2d(get_velocity().get_x(),0));
						set_position(vec2d(position.get_x(),position.get_y()+collision.collision_rectangle().get_height()+1));
                        break;
					}
				}
				else{
					if(collision.collision_rectangle().contains(vec2d(right_x,llc_y))){
							set_velocity(vec2d(0,0));
							set_position(vec2d(position.get_x()-collision.collision_rectangle().get_width()-1,position.get_y()));
							break;

					}
					else {//if(collision.collision_rectangle().upper_left_corner().get_x()+collision.collision_rectangle().get_width()-left_x >= 0){
							cout<<"here";
							set_velocity(vec2d(0,0));
							set_position(vec2d(position.get_x()+collision.collision_rectangle().get_width()+1,position.get_y()));
							break;
					}
				}




			}
            return;
		}

        else if(other->is_passive()==false){
            while(collision.is_active()){
                cout<<"y u here"<<endl;
				//Player Y cords

				float lrc_y=this->bounding_box().lower_right_corner().get_y();
				float ulc_y=this->bounding_box().upper_left_corner().get_y();
				float llc_y=ulc_y+this->bounding_box().get_height();
				float urc_y=lrc_y-this->bounding_box().get_height();

				//Player X cords
				float right_x=this->bounding_box().lower_right_corner().get_x();
				float left_x=this->bounding_box().upper_left_corner().get_x();

				if(collision.collision_rectangle().get_width()>collision.collision_rectangle().get_height()){
					//Bottom Collision
					//if(lrc_y >= other->get_y() || llc_y >= other->get_y()){
					if(collision.collision_rectangle().contains(vec2d(left_x,llc_y)) || collision.collision_rectangle().contains(vec2d(right_x,lrc_y))){
                        //other->kill(true);
                        kill=true;
                        set_position(vec2d(position.get_x(),position.get_y()-collision.collision_rectangle().get_height()-1));
						break;
					}
					else{
					}
				}
				else{
					//if(collision.collision_rectangle().lower_right_corner().get_x()-right_x < 0){
					if(collision.collision_rectangle().contains(vec2d(right_x,llc_y))){
						//if(right_x >= other->get_x()){
                            alive=false;
							break;
						//}


					}
					else if(collision.collision_rectangle().upper_left_corner().get_x()+collision.collision_rectangle().get_width()-left_x >= 0){
						//if(left_x <= other->get_x()+other->get_width()){
							cout<<"here";
                            alive=false;
							break;
						//}
					}
				}
        }
    }

  }
  void player_sprite::stand(){
  	set_image_sequence(st);
  }
  void player_sprite::move_right(){
    set_image_sequence(run_R);

  }

  void player_sprite::move_left(){
  	set_image_sequence(run_L);
  }

  bool player_sprite::jump(){
  	if(on_ground==false)
  		return on_ground;
  	else{
  		on_ground=false;
  		return true;

  	}
  }

  bool player_sprite::is_kill(){
      return kill;
  }
  void player_sprite::set_kill(bool a){
      kill=a;
  }

}
