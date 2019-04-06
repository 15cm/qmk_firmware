#ifndef PASSWORD_MY_H
#define PASSWORD_MY_H

#define S_PWD M(0)

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
    case 0:
        if (record->event.pressed) {
            return MACRO( I(1), T(A), T(B), T(C), T(1), T(2), T(3), T(ENT), END );
        }
        break;
    }
    return MACRO_NONE;
};

#endif
