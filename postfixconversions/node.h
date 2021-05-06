#pragma once

template <typename N>
class node
{
	template <typename T>
	friend class stack;
	N data;
	node<N>* next;
public:
	node(N d, node<N>* n = nullptr);
};

