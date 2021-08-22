#define WHITE { HSV_WHITE }
#define RED { HSV_RED }
#define CORAL { HSV_CORAL }
#define ORANGE { HSV_ORANGE }
#define GOLDENROD { HSV_GOLDENROD }
#define GOLD { HSV_GOLD }
#define YELLOW { HSV_YELLOW }
#define CHARTREUSE { HSV_CHARTREUSE }
#define GREEN { HSV_GREEN }
#define SPRINGGREEN { HSV_SPRINGGREEN }
#define TURQUOISE { HSV_TURQUOISE }
#define TEAL { HSV_TEAL }
#define CYAN { HSV_CYAN }
#define AZURE { HSV_AZURE }
#define BLUE { HSV_BLUE }
#define PURPLE { HSV_PURPLE }
#define MAGENTA { HSV_MAGENTA }
#define PINK { HSV_PINK }
#define NONE { HSV_OFF }

PROGMEM uint8_t ledmap[][DRIVER_LED_TOTAL][3] = {
    [MacbookLayer] = {
        ORANGE    , CYAN        , CYAN        , CYAN        , ORANGE      ,
        GOLDENROD , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , NONE        ,
        GOLDENROD , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , ORANGE      ,
        GOLDENROD , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , CYAN        ,
        GOLDENROD , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , CYAN        ,
        GOLDENROD , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN ,
        GOLDENROD , SPRINGGREEN , ORANGE      ,
        GOLDENROD , GOLDENROD   , MAGENTA     ,
        WHITE     ,

        CYAN      , SPRINGGREEN , CYAN        , CYAN        , GOLD        ,
        GOLDENROD , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , GOLD        ,
        GOLDENROD , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , GOLD        ,
        GOLDENROD , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , GOLD        ,
        GOLDENROD , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN ,
        GOLDENROD , SPRINGGREEN , SPRINGGREEN , SPRINGGREEN ,
        GOLDENROD , ORANGE      , ORANGE      ,
        WHITE     , CYAN        , MAGENTA     ,
        WHITE
    },

    [WindowsLayer] = {
        CORAL     , GREEN     , GREEN , GREEN , CORAL ,
        GOLDENROD , CYAN      , CYAN  , CYAN  , NONE  ,
        GOLDENROD , CYAN      , CYAN  , CYAN  , CORAL ,
        GOLDENROD , CYAN      , CYAN  , CYAN  , GREEN ,
        GOLDENROD , CYAN      , CYAN  , CYAN  , GREEN ,
        GOLDENROD , CYAN      , CYAN  , CYAN  ,
        GOLDENROD , CYAN      , CORAL ,
        GOLDENROD , GOLDENROD , BLUE  ,
        WHITE     ,

        GREEN     , CYAN      , GREEN , GREEN , GOLD  ,
        GOLDENROD , CYAN      , CYAN  , CYAN  , GOLD  ,
        GOLDENROD , CYAN      , CYAN  , CYAN  , GOLD  ,
        GOLDENROD , CYAN      , CYAN  , CYAN  , GOLD  ,
        GOLDENROD , CYAN      , CYAN  , CYAN  , CYAN  ,
        GOLDENROD , CYAN      , CYAN  , CYAN  ,
        GOLDENROD , CORAL     , CORAL ,
        WHITE     , GREEN , BLUE  ,
        WHITE
    },

    [GameLayer] = {
        ORANGE , NONE , NONE , ORANGE , ORANGE ,
        NONE   , NONE , GOLD , NONE   , NONE   ,
        NONE   , GOLD , GOLD , NONE   , NONE   ,
        NONE   , NONE , GOLD , NONE   , BLUE   ,
        NONE   , NONE , NONE , NONE   , ORANGE ,
        NONE   , NONE , NONE , NONE   ,
        NONE   , NONE , RED  ,
        WHITE  , NONE , NONE ,
        BLUE   ,

        NONE   , NONE , NONE , NONE   , NONE   ,
        NONE   , NONE , NONE , NONE   , GOLD   ,
        NONE   , NONE , NONE , GOLD   , GOLD   ,
        NONE   , NONE , NONE , NONE   , GOLD   ,
        NONE   , NONE , NONE , NONE   , NONE   ,
        NONE   , NONE , NONE , NONE   ,
        NONE   , NONE , NONE ,
        NONE   , NONE , NONE ,
        NONE
    },

    [SymbolLayer] = {
        PINK        , MAGENTA     , MAGENTA   , MAGENTA , PINK      ,
        NONE        , CYAN        , NONE      , NONE    , NONE      ,
        NONE        , CYAN        , TURQUOISE , NONE    , NONE      ,
        NONE        , CYAN        , TURQUOISE , NONE    , MAGENTA   ,
        NONE        , CYAN        , TURQUOISE , NONE    , MAGENTA   ,
        NONE        , CYAN        , NONE      , NONE    ,
        NONE        , CYAN        , NONE      ,
        NONE        , NONE        , NONE      ,
        NONE        ,

        RED         , NONE        , NONE      , NONE    , NONE      ,
        NONE        , NONE        , GOLDENROD , CYAN    , NONE      ,
        NONE        , CORAL       , CORAL     , CYAN    , NONE      ,
        NONE        , CORAL       , CORAL     , CYAN    , NONE      ,
        NONE        , ORANGE      , GREEN     , GREEN   , TURQUOISE ,
        NONE        , NONE        , ORANGE    , ORANGE  ,
        RED         , NONE        , NONE      ,
        SPRINGGREEN , SPRINGGREEN , NONE      ,
        NONE
    },

    [MouseLayer] = {
        NONE    , NONE   , CYAN    , CYAN , NONE ,
        NONE    , NONE   , NONE    , NONE , NONE ,
        NONE    , NONE   , NONE    , NONE , NONE ,
        NONE    , NONE   , NONE    , NONE , CYAN ,
        NONE    , NONE   , NONE    , NONE , CYAN ,
        NONE    , NONE   , NONE    , NONE ,
        NONE    , NONE   , NONE    ,
        NONE    , NONE   , NONE    ,
        NONE    ,

        NONE    , NONE   , NONE    , NONE , NONE ,
        NONE    , NONE   , AZURE   , NONE , NONE ,
        NONE    , RED    , GOLD    , BLUE , NONE ,
        NONE    , GOLD   , GOLD    , BLUE , NONE ,
        NONE    , RED    , GOLD    , BLUE , NONE ,
        NONE    , NONE   , RED     , RED  ,
        NONE    , NONE   , NONE    ,
        MAGENTA , YELLOW , MAGENTA ,
        NONE
    },

    [NumpadLayer] = {
        NONE      , NONE      , NONE  , NONE  , NONE  ,
        NONE      , NONE      , NONE  , NONE  , NONE  ,
        NONE      , NONE      , NONE  , NONE  , NONE  ,
        NONE      , NONE      , NONE  , NONE  , NONE  ,
        NONE      , NONE      , NONE  , NONE  , NONE  ,
        NONE      , NONE      , NONE  , NONE  ,
        NONE      , NONE      , NONE  ,
        NONE      , NONE      , NONE  ,
        NONE      ,

        NONE      , NONE      , NONE  , NONE  , NONE  ,
        RED       , GREEN     , WHITE , NONE  , NONE  ,
        ORANGE    , AZURE     , AZURE , AZURE , NONE  ,
        MAGENTA   , AZURE     , AZURE , AZURE , GOLD  ,
        WHITE     , AZURE     , AZURE , AZURE , AZURE ,
        NONE      , NONE      , NONE  , NONE  ,
        NONE      , NONE      , NONE  ,
        TURQUOISE , TURQUOISE , NONE  ,
        NONE
    },

    [FuncLayer] = {
        NONE       , NONE       , NONE      , NONE      , WHITE  ,
        CHARTREUSE , RED        , NONE      , NONE      , NONE   ,
        CHARTREUSE , NONE       , CYAN      , YELLOW    , NONE   ,
        CHARTREUSE , NONE       , BLUE      , GREEN     , NONE   ,
        CHARTREUSE , NONE       , CYAN      , YELLOW    , NONE   ,
        CHARTREUSE , NONE       , GOLDENROD , GOLDENROD ,
        CHARTREUSE , NONE       , MAGENTA   ,
        NONE       , NONE       , ORANGE    ,
        NONE       ,

        CHARTREUSE , CHARTREUSE , NONE      , NONE      , AZURE  ,
        CHARTREUSE , NONE       , NONE      , NONE      , NONE   ,
        CHARTREUSE , NONE       , GOLDENROD , GOLDENROD , NONE   ,
        CHARTREUSE , NONE       , NONE      , CYAN      , NONE   ,
        CHARTREUSE , NONE       , NONE      , CYAN      , PURPLE ,
        CHARTREUSE , NONE       , GOLDENROD , GOLDENROD ,
        CHARTREUSE , NONE       , RED       ,
        NONE       , MAGENTA    , ORANGE    ,
        NONE
    },

    [ArrowsLayer] = {
        NONE , NONE    , WHITE   , WHITE , NONE  ,
        NONE , NONE    , NONE    , NONE  , NONE  ,
        NONE , NONE    , NONE    , PINK  , NONE  ,
        NONE , PINK    , NONE    , NONE  , NONE  ,
        NONE , NONE    , NONE    , NONE  , WHITE ,
        NONE , NONE    , NONE    , NONE  ,
        NONE , NONE    , NONE    ,
        NONE , NONE    , NONE    ,
        NONE ,

        NONE , NONE    , NONE    , NONE  , NONE  ,
        NONE , NONE    , NONE    , NONE  , NONE  ,
        NONE , NONE    , GOLD    , NONE  , NONE  ,
        NONE , PINK    , GOLD    , NONE  , NONE  ,
        NONE , NONE    , GOLD    , NONE  , NONE  ,
        NONE , NONE    , GOLD    , NONE  ,
        NONE , NONE    , NONE    ,
        NONE , MAGENTA , MAGENTA ,
        NONE
    },
};

