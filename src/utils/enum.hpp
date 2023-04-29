#ifndef FRUIT_H 
#define FRUIT_H 

enum FruitType{
    APPLE,
    BANANA,
    ORANGE
};
// recibe un valor de FruitType y devuelva un string
string fruitTypeToString(FruitType f) {
  switch (f) { 
    case APPLE: return "manzanas"; // Si es APPLE, devolver "manzanas"
    case BANANA: return "bananas"; // Si es BANANA, devolver "bananas"
    case ORANGE: return "naranjas"; // Si es ORANGE, devolver "naranjas"
  }
}
#endif 

#ifndef STATUS 
#define STATUS 
enum Status{
    READY = 3,
    IN_PROGRESS = 4,
    FINISHED = 5
};

string statusToString(Status s) {
  switch (s) { 
    case READY: return "READY"; // Si es READY, devolver "READY"
    case IN_PROGRESS: return "IN_PROGRESS"; // Si es IN_PROGRESS, devolver "IN_PROGRESS"
    case FINISHED: return "FINISHED"; // Si es FINISHED, devolver "FINISHED"
  }
}
#endif




