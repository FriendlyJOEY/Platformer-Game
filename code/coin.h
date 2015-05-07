#ifndef __CDS_COIN_H
#define __CDS_COIN_H

#include "sprite.h"

namespace csis3700 {

  /**
   * obstruction_sprites don't typically move and when they
   * participate in a collision they are unimpacted by it. They
   * typically render themslves as a single, static bitmap.
   */
  class coin : public sprite {
  public:
    coin(float initial_x, float initial_y, ALLEGRO_BITMAP *image=NULL);
    virtual void set_velocity(const vec2d& v);
    virtual vec2d get_velocity() const;
    virtual void resolve(const collision& collision, sprite* other);
    virtual bool is_coin();
  };
}


#endif /* COIN_H */
