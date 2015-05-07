#ifndef __CDS_WORLD_H
#define __CDS_WORLD_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "sprite.h"
#include "player_sprite.h"
#include "badguy.h"
#include "coin.h"
#include <vector>
#include <sstream>
#include <cstring>

namespace csis3700 {
  class world {
  public:
    /**
     * Construct the world. The display is passed in simply to make it
     * possible to modify options or access the backbuffer. DO NOT
     * store the display in an instance variable. DO NOT start drawing
     * on the screen. Just load bitmaps etc.
     */
    world();

    /**
     * Free any resources being used by the world.
     */
    ~world();

    /**
     * Block the copy constructor.  Worlds should not be copied to
     * just assert(false)
     */
    world(const world& other);

    /**
     * Block operator =.  Worlds should not be assigned.
     */
    world& operator =(const world& other);

    /**
     * Update the state of the world based on the event ev.
     */
    void handle_event(ALLEGRO_EVENT ev);

    /**
     * Advance the state of the world forward by the specified time.
     */
    void advance_by_time(double dt);

    /**
     * Draw the world. Note that the display variable is passed only
     * because it might be needed to switch the target bitmap back to
     * the backbuffer.
     */
    void draw();

    //Sets Background
    void set_bg(ALLEGRO_BITMAP* b);

    void set_player_cords(double x,double y);

    void add_sprite(sprite* s);

    void add_rect(float x, float y,float h,float w);

    void add_sprite2(sprite*s);

  private:
    void resolve_collisions();
    int points;
    bool islevel2;
    int kills;
    std::stringstream points_ss;
    std::string points_s;
    ALLEGRO_FONT *font_20;
    badguy *bad;
    coin *c;
    player_sprite *player;
    std::vector<badguy*> badguys;
    std::vector<sprite*> sprites;
    std::vector<sprite*> sprites2;
    std::vector<rectangle*> rect;
    rectangle* pr;
    ALLEGRO_BITMAP* background;
    double px,py;
  };
}

#endif /* WORLD_H */
