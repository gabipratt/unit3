//#ifndef WILL || ANNA || BERT || CLAUS
//#error "You must define a personality for the shybot"
//#endif
//
#if defined(WILL)
#pragma message("Using WILLs personality")
#define LIGHT_THRESHOLD 400
#define PARANOID_LIGHT_THRESHOLD 950
#endif

#if defined(ANNA)
#pragma message("Using ANNAs personality")
#define LIGHT_THRESHOLD 100
#define PARANOID_LIGHT_THRESHOLD 980
#endif

#if defined(BERT)
#pragma message("Using BERTs personality")
#define LIGHT_THRESHOLD 200
#define PARANOID_LIGHT_THRESHOLD 800
#endif

#if defined(CLAUS)
#pragma message("Using CLAUSs personality")
#define LIGHT_THRESHOLD 100
#define PARANOID_LIGHT_THRESHOLD 750
#endif

