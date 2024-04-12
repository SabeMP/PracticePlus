#include "PlayerCheckpoint.hpp"
#include <hooks/cocos2d/CCNode.hpp>
#include <util/debug.hpp>

using namespace geode::prelude;

void PPPlayerCheckpoint::load(InputStream& i_stream) {
	reinterpret_cast<PPCCNode*>(this)->load(i_stream);
	i_stream >> *this;
}

void PPPlayerCheckpoint::save(OutputStream& o_stream) {
	reinterpret_cast<PPCCNode*>(this)->save(o_stream);
	o_stream << *this;
}

inline void operator>>(InputStream& i_stream, PPPlayerCheckpoint& o_value) {
	i_stream >> o_value.m_position;
	SEPARATOR_I
	i_stream >> o_value.m_lastPosition;
	SEPARATOR_I
	i_stream >> o_value.m_unkInt1;
	SEPARATOR_I
	i_stream >> o_value.m_isUpsideDown;
	SEPARATOR_I
	i_stream >> o_value.m_unk7b3;
	SEPARATOR_I
	i_stream >> o_value.m_isShip;
	SEPARATOR_I
	i_stream >> o_value.m_isBall;
	SEPARATOR_I
	i_stream >> o_value.m_isBird;
	SEPARATOR_I
	i_stream >> o_value.m_isSwing;
	SEPARATOR_I
	i_stream >> o_value.m_isDart;
	SEPARATOR_I
	i_stream >> o_value.m_isRobot;
	SEPARATOR_I
	i_stream >> o_value.m_isSpider;
	SEPARATOR_I
	i_stream >> o_value.m_isOnGround;
	SEPARATOR_I
	i_stream >> o_value.m_hasGhostTrail;
	SEPARATOR_I
	i_stream.read((char*)o_value.m_unkBytes1, 4);
	SEPARATOR_I
	i_stream >> o_value.m_speed;
	SEPARATOR_I
	i_stream >> o_value.m_isHidden;
	SEPARATOR_I
	i_stream >> o_value.m_isGoingLeft;
	SEPARATOR_I
	i_stream.read((char*)o_value.m_unkBytes2, 42);
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat1;
	SEPARATOR_I
	i_stream >> o_value.m_possiblyFlags;
	SEPARATOR_I
	i_stream >> o_value.m_timeOrPercentRelated;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_yPositionVector;
	VEC_SEPARATOR_I
	i_stream.read((char*)o_value.m_unkBytes3, 8);
	SEPARATOR_I
}

inline void operator<<(OutputStream& o_stream, PPPlayerCheckpoint& i_value) {
	o_stream << i_value.m_position;
	SEPARATOR_O
	o_stream << i_value.m_lastPosition;
	SEPARATOR_O
	o_stream << i_value.m_unkInt1;
	SEPARATOR_O
	o_stream << i_value.m_isUpsideDown;
	SEPARATOR_O
	o_stream << i_value.m_unk7b3;
	SEPARATOR_O
	o_stream << i_value.m_isShip;
	SEPARATOR_O
	o_stream << i_value.m_isBall;
	SEPARATOR_O
	o_stream << i_value.m_isBird;
	SEPARATOR_O
	o_stream << i_value.m_isSwing;
	SEPARATOR_O
	o_stream << i_value.m_isDart;
	SEPARATOR_O
	o_stream << i_value.m_isRobot;
	SEPARATOR_O
	o_stream << i_value.m_isSpider;
	SEPARATOR_O
	o_stream << i_value.m_isOnGround;
	SEPARATOR_O
	o_stream << i_value.m_hasGhostTrail;
	SEPARATOR_O
	o_stream.write((char*)i_value.m_unkBytes1, 4);
	SEPARATOR_O
	o_stream << i_value.m_speed;
	SEPARATOR_O
	o_stream << i_value.m_isHidden;
	SEPARATOR_O
	o_stream << i_value.m_isGoingLeft;
	SEPARATOR_O
	o_stream.write((char*)i_value.m_unkBytes2, 42);
	SEPARATOR_O
	o_stream << i_value.m_unkFloat1;
	SEPARATOR_O
	o_stream << i_value.m_possiblyFlags;
	SEPARATOR_O
	o_stream << i_value.m_timeOrPercentRelated;
	VEC_SEPARATOR_O
	o_stream << i_value.m_yPositionVector;
	VEC_SEPARATOR_O
	o_stream.write((char*)i_value.m_unkBytes3, 8);
	SEPARATOR_O
}

#ifdef PP_DEBUG
void PPPlayerCheckpoint::describe() {
	log::info("[PPPlayerCheckpoint - describe] m_position: {}", m_position);
	log::info("[PPPlayerCheckpoint - describe] m_lastPosition: {}", m_lastPosition);
	log::info("[PPPlayerCheckpoint - describe] m_unkInt1: {}", m_unkInt1);
	log::info("[PPPlayerCheckpoint - describe] m_isUpsideDown: {}", m_isUpsideDown);
	log::info("[PPPlayerCheckpoint - describe] m_unk7b3: {}", m_unk7b3);
	log::info("[PPPlayerCheckpoint - describe] m_isShip: {}", m_isShip);
	log::info("[PPPlayerCheckpoint - describe] m_isBall: {}", m_isBall);
	log::info("[PPPlayerCheckpoint - describe] m_isBird: {}", m_isBird);
	log::info("[PPPlayerCheckpoint - describe] m_isSwing: {}", m_isSwing);
	log::info("[PPPlayerCheckpoint - describe] m_isDart: {}", m_isDart);
	log::info("[PPPlayerCheckpoint - describe] m_isRobot: {}", m_isRobot);
	log::info("[PPPlayerCheckpoint - describe] m_isSpider: {}", m_isSpider);
	log::info("[PPPlayerCheckpoint - describe] m_isOnGround: {}", m_isOnGround);
	log::info("[PPPlayerCheckpoint - describe] m_hasGhostTrail: {}", m_hasGhostTrail);
	log::info("[PPPlayerCheckpoint - describe] m_unkBytes1: [{}]", hexStr(m_unkBytes1, 4));
	log::info("[PPPlayerCheckpoint - describe] m_speed: {}", m_speed);
	log::info("[PPPlayerCheckpoint - describe] m_isHidden: {}", m_isHidden);
	log::info("[PPPlayerCheckpoint - describe] m_isGoingLeft: {}", m_isGoingLeft);
	log::info("[PPPlayerCheckpoint - describe] m_unkBytes2: [{}]", hexStr(m_unkBytes2, 42));
	log::info("[PPPlayerCheckpoint - describe] m_position: {}", m_unkFloat1);
	log::info("[PPPlayerCheckpoint - describe] m_position: {}", m_possiblyFlags);
	log::info("[PPPlayerCheckpoint - describe] m_position: {}", m_timeOrPercentRelated);
	int l_size = m_yPositionVector.size();
	log::info("[PPPlayerCheckpoint - describe] m_yPositionVector.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PPPlayerCheckpoint - describe] m_yPositionVector[{}]: {}", i, m_yPositionVector[i]);
	}
	log::info("[PPPlayerCheckpoint - describe] m_unkBytes3: [{}]", hexStr(m_unkBytes3, 8));
}
#endif