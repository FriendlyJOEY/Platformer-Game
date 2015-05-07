#include "coin.h"
#include "image_library.h"
#include "image_sequence.h"

namespace csis3700 {
  coin::coin(float initial_x, float initial_y, ALLEGRO_BITMAP *image) : sprite(initial_x, initial_y) {
    sequence=new image_sequence();
    sequence->add_image(image,0);
  }

  vec2d coin::get_velocity() const {
    return vec2d(0,0);
  }

  void coin::set_velocity(const vec2d& v) {
    assert(false);
  }

  void coin::resolve(const collision& collision, sprite* other) {
    // do nothing, I am not an active participant in a collision
  }

  bool coin::is_coin(){
      return true;
  }

}
