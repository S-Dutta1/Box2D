/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

/* 
 * Base code for CS 251 Software Systems Lab 
 * Department of Computer Science and Engineering, IIT Bombay
 * 
 */


#include "cs251_base.hpp"
#include "render.hpp"

#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include "GL/freeglut.h"
#endif

#include <cstring>
using namespace std;

#include "dominos.hpp"

namespace cs251
{
  /**  The is the constructor 
   * This is the documentation block for the constructor.
   */ 
  
  dominos_t::dominos_t()
  {
    //Ground
    /*! \var b1 
     * \brief pointer to the body ground 
     */ 
    b2Body* b1;  
    {
      
      b2EdgeShape shape; 
      shape.Set(b2Vec2(-90.0f, 0.0f), b2Vec2(90.0f, 0.0f));
      b2BodyDef bd; 
      b1 = m_world->CreateBody(&bd); 
      b1->CreateFixture(&shape, 0.0f);
    }
          
 

    //The left and right sphere
    {
      b2Body* lballl;b2Body* lballr;b2Body* sballc;b2Body* sballr;
      
      b2CircleShape circle;
      circle.m_radius = 5.0;
	
      b2FixtureDef lball;
      lball.shape = &circle;
      lball.density = 50.0f;
      lball.friction = 0.0f;
      lball.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_staticBody;
      ballbd.position.Set(14.0f, 18.0f);
      lballl = m_world->CreateBody(&ballbd);
      lballl->CreateFixture(&lball);

      ballbd.position.Set(-14.0f, 18.0f);
      lballr = m_world->CreateBody(&ballbd);
      lballr->CreateFixture(&lball);
    
    
    

      b2CircleShape scircle;
      scircle.m_radius = 1.0;
  
      b2FixtureDef sball;
      sball.shape = &scircle;
      sball.density = 1.0f;
      sball.friction = 0.0f;
      sball.restitution = 0.7f;
      b2BodyDef ballbds;
      ballbds.type = b2_dynamicBody;

      ballbds.position.Set(0.0f, 25.0f);
      sballc = m_world->CreateBody(&ballbds);
      sballc->CreateFixture(&sball);

      ballbds.position.Set(5.0f, 18.0f);
      sballr = m_world->CreateBody(&ballbds);
      sballr->CreateFixture(&sball);

      
       //sballc->ApplyForce(b2Vec2(10.0f,0.0f), sballc->GetWorldCenter(),true);
     



    }

    //  b2Body* bodies[3];

    //  b2BodyDef myBodyDef;
    // myBodyDef.type = b2_dynamicBody;
    
    // //shape definition
    // b2PolygonShape polygonShape;
    // polygonShape.SetAsBox(1, 1); //a 2x2 rectangle
  
    // //fixture definition
    // b2FixtureDef myFixtureDef;
    // myFixtureDef.shape = &polygonShape;
    // myFixtureDef.density = 1;
    
    // //create identical bodies in different positions
    // for (int i = 0; i < 3; i++) {
    //   myBodyDef.position.Set(-10+i*10, 20);
    //   bodies[i] = m_world->CreateBody(&myBodyDef);
    //   bodies[i]->CreateFixture(&myFixtureDef);
    // }
    
    // //a static floor to drop things on
    // myBodyDef.type = b2_staticBody;
    // myBodyDef.position.Set(0, 0);
    // //polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) );
    // m_world->CreateBody(&myBodyDef)->CreateFixture(&myFixtureDef);
    // for(int i=0;i<100;i++)
    //   bodies[0]->ApplyForce( b2Vec2(0,50), bodies[0]->GetWorldCenter(),true);
     


   
   }

  sim_t *sim = new sim_t("Dominos", dominos_t::create);
}
