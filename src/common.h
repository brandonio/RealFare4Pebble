
void lainit(void);
void ladeinit(void);

void sfinit(void);
void sfdeinit(void);

void nycinit(void);
void nycdeinit(void);

typedef struct pricing {
    float base;
    float perMin;
    float perMile;
    float safe;
    float min;
  } pricing;

void pricesinit(int index);
void pricesdeinit(void);

