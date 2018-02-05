#ifndef ENUMCARDTYPE
#define ENUMCARDTYPE

enum CardType {
    NONE   = 256,
    REVIEW = 0,
    MULTI  = 1,
    INPUT  = 2,
    CREATE = 16,
    EDIT   = 17
};

enum MessageType {
    CORRECT = 0,
    WRONG   = 1
};

#endif // ENUMCARDTYPE

