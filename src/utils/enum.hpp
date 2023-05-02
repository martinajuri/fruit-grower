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
    PENDING,
    IN_PROGRESS,
    FINISHED
};

string statusToString(Status s) {
  switch (s) { 
    case PENDING: return "PENDIENTE"; // Si es PENDING, devolver "PENDIENTE"
    case IN_PROGRESS: return "EN PROGRESO"; // Si es IN_PROGRESS, devolver "EN PROGRESO"
    case FINISHED: return "FINALIZADO"; // Si es FINISHED, devolver "FINALIZADO"
  }
}
#endif




