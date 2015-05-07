#ifndef __CDS_PLAYER_SPRITE_H
#define __CDS_PLAYER_SPRITE_H
#include "phys_sprite.h"

namespace csis3700 {
  class player_sprite : public phys_sprite {
  public:
    player_sprite(float initial_x=0, float initial_y=0);
    virtual bool is_passive() const;
    virtual void set_on_ground(bool v);
    virtual void advance_by_time(double dt);
    virtual void resolve(const collision& collision, sprite* other);
    virtual void move_right();
    virtual void stand();
    virtual void move_left();
    virtual bool jump();
    virtual void draw();
    virtual bool is_kill();
    virtual void set_kill(bool a);
  private:
    bool on_ground,alive,kill;
    image_sequence *run_L, *st,*run_R;
  };
}


#endif /* PLAYER_SPRITE_H */
