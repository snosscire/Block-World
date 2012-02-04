#include "Block.h"
#include "World.h"
#include "Camera.h"
#include "Engine/Engine.h"

#include <iostream>

namespace BlockWorld {
	Block::Block() :
		m_type(BLOCK_TYPE_NONE),
		m_world(NULL),
		m_x(0),
		m_y(0)
	{
	}
	
	Block::Block(World* world, unsigned int x, unsigned int y) :
		m_type(BLOCK_TYPE_NONE),
		m_world(world),
		m_x(x),
		m_y(y)
	{
	}
	
	Block::~Block()
	{
	}
	
	BlockType Block::getType()
	{
		return m_type;
	}
	
	void Block::setX(unsigned int x)
	{
		m_x = x;
	}
	
	void Block::setY(unsigned int y)
	{
		m_y = y;
	}
	
	void Block::update()
	{
	}
	
	void Block::draw(Engine* engine, Camera* camera)
	{
		/*
		SDL_Rect dst;
		dst.x = (self->x * BLOCK_WIDTH) - MineCamera_Left(camera);
		dst.y = (self->y * BLOCK_HEIGHT) - MineCamera_Top(camera);
		dst.w = BLOCK_WIDTH;
		dst.h = BLOCK_HEIGHT;
		
		SDL_BlitSurface(self->image, NULL, MineEngine_VideoSurface, &dst);
		*/
	}
};
