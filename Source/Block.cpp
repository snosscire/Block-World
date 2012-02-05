#include "Block.h"
#include "World.h"
#include "Camera.h"
#include "Engine/Engine.h"

#include <iostream>

namespace BlockWorld {
	Block::Block() :
		m_type(BLOCK_TYPE_NONE),
		m_position(),
		m_world(NULL)
	{
	}
	
	Block::Block(World* world, unsigned int x, unsigned int y) :
		m_type(BLOCK_TYPE_NONE),
		m_position(x, y),
		m_world(world)
	{
	}
	
	Block::~Block()
	{
	}
	
	BlockType Block::getType()
	{
		return m_type;
	}
	
	void Block::setPosition(unsigned int x, unsigned int y)
	{
		m_position.setX(x);
		m_position.setY(y);
	}
		
	void Block::update()
	{
	}
	
	void Block::draw(Engine& engine, Camera& camera)
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
