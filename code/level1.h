#ifndef __LEVEL1_H
#define __LEVEL1_H
#include <cassert>
#include <algorithm>
#include "sprite.h"
#include "image_library.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "player_sprite.h"
#include "obstruction_sprite.h"
#include "collision.h"

namespace csis3700 {
	class world;
  class level1 {
  public:
	void populate(world &w);
	
	
	private:
		obstruction_sprite* os;
  };
}


#endif /* PLAYER_SPRITE_H */
