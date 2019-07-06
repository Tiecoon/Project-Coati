#pragma once

//STD Headers
#include <unordered_map>
#include <functional>

//Library Headers

//Coati Headers
#include "Message.h"

namespace EngineCore {

	//Forward Class declarations


	class EventTable {
	private:
		//Private Class Members
		std::unordered_map<Message, std::function<void()>> Events;

	public:
		//CTORS
		EventTable() = default;
		~EventTable() = default;

		std::function<void()> operator[] (const Message& event) const;


	private:
		//Private member functions

	public:
		//Public member functions
		bool BindEvent(const Message &message, const std::function<void()> &event);
		bool UnbindEvent(const Message &message);
	};

}