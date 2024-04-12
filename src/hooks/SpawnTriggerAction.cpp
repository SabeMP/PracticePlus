#include "SpawnTriggerAction.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include <hooks/cocos2d/CCNode.hpp>
#include <util/debug.hpp>

using namespace geode::prelude;

void PPSpawnTriggerAction::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PPSpawnTriggerAction::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void operator>>(InputStream& i_stream, PPSpawnTriggerAction& o_value) {
	i_stream.read(reinterpret_cast<char*>(o_value.pad_1), 40);
	SEPARATOR_I
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PlayLayer* l_playLayer = PlayLayer::get();
	if (l_playLayer && l_objectIndex != -1) {
		o_value.m_gameObject = static_cast<GameObject*>(l_playLayer->m_objects->objectAtIndex(l_objectIndex));
	} else {
		o_value.m_gameObject = nullptr;
	}
	VEC_SEPARATOR_I
	int l_size = o_value.m_unkVecInt.size();
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
}

inline void operator<<(OutputStream& o_stream, PPSpawnTriggerAction& i_value) {
	o_stream.write(reinterpret_cast<char*>(i_value.pad_1), 40);
	SEPARATOR_O
	int l_objectIndex = -1;
	if (i_value.m_gameObject) {
		l_objectIndex = i_value.m_gameObject->m_uniqueID-12;
	}
	o_stream << l_objectIndex;
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
}

#ifdef PP_DEBUG
void PPSpawnTriggerAction::describe() {
	log::info("[PPSpawnTriggerAction - describe] pad_1: [{}]", hexStr(pad_1, 40));
	int l_objectIndex = -1;
	if (m_gameObject) {
		l_objectIndex = m_gameObject->m_uniqueID-12;
	}
	log::info("[PPSpawnTriggerAction - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
	int l_size = m_unkVecInt.size();
	log::info("[PPSpawnTriggerAction - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PPSpawnTriggerAction - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
}
#endif