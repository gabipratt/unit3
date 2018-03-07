
#if defined(WILL)
#pragma message("Using WILLs personality")
#define SENSITIVITY 1.12
#define LIGHT_THRESHOLD 400
#define PARANOID_LIGHT_THRESHOLD 950
#endif

#if defined(ANNA)
#pragma message("Using ANNAs personality")
#define SENSITIVITY 0.92
#define LIGHT_THRESHOLD 100
#define PARANOID_LIGHT_THRESHOLD 980
#endif

#if defined(BERT)
#pragma message("Using BERTs personality")
#define SENSITIVITY 0.8
#define LIGHT_THRESHOLD 200
#define PARANOID_LIGHT_THRESHOLD 800
#endif

#if defined(CLAUS)
#pragma message("Using CLAUSs personality")
#define SENSITIVITY 0.8
#define LIGHT_THRESHOLD 100
#define PARANOID_LIGHT_THRESHOLD 900
#endif

