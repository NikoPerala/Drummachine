#ifndef EPHO_BITWISE_MAKROS_H
#define EPHO_BITWISE_MAKROS_H

#define TOGGLE_BIT(d, b) d ^= (1 << b)
#define CHECK_BIT(d, b) !!(d & (1 << b))
#define SET_BIT(d, b) d |= (1 << b)
#define CLEAR_BIT(d, b) d &= ~(1 << b)

#endif // EPHO_BITWISE_MAKROS_H
