#include "badguy.h"
#include "image_library.h"
#include "image_sequence.h"
#include "vec2d.h"
#include "collision.h"
#include <cmath>
using namespace std;

namespace csis3700 {

 badguy::badguy(float initial_x, float initial_y,float x_mx,float x_mn) :
    phys_sprite(initial_x, initial_y) {
        sequence = new image_sequence();
        sequence->add_image(image_library::get_instance()->get("badguy.png"),0);
        on_ground=false;
        x_max=x_mx;
        x_min=x_mn;
        direction=1;
        killplayer=false;
    }
    bool badguy::is_passive() const {
      return false;
    }

    void badguy::set_on_ground(bool v) {
      on_ground = v;
    }

    void badguy::advance_by_time(double dt) {
      if(get_x()>=x_max)
        direction=-1;
      if(get_x()<=x_min)
        direction=1;
      set_velocity(vec2d(direction*50,0));
      phys_sprite::advance_by_time(dt);
    }
    void badguy::draw(){
        if(killbadguy==false){
            sprite::draw();
        }
    }

    void badguy::stand(){
        set_image_sequence(st);
    }
    void badguy::move_right(){
      set_image_sequence(run_R);

    }

    void badguy::move_left(){
        set_image_sequence(run_L);
    }
    void badguy::resolve(const collision& collision, sprite* other){
            /*while(collision.is_active()){
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
                        cout<<"here"<<endl;
                        killbadguy=true;
                        break;
                    }
                    else{
                        cout<<"here"<<endl;
                        killbadguy=true;
                        set_position(vec2d(10000,10000));
                        break;
                    }
                }
                else{
                    if(collision.collision_rectangle().contains(vec2d(right_x,llc_y))){
                        cout<<"here"<<endl;
                        killbadguy=true;
                        break;
                    }
                    else if(collision.collision_rectangle().upper_left_corner().get_x()+collision.collision_rectangle().get_width()-left_x >= 0){
                        cout<<"here"<<endl;
                            killbadguy=true;
                            break;
                    }
                }




            }*/

    }

    bool badguy::jump(){
        if(on_ground==false)
            return on_ground;
        else{
            on_ground=false;
            return true;

        }
    }
    bool badguy::kill(bool k){
        killbadguy=k;
    }
}
