#include "node.h"
template <typename N> node <N>::node(N d, node<N>* n) {
	data = d;
	next = n;
}
