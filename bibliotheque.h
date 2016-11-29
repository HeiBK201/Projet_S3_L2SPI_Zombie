#define N 20
#define Z 50

//Bibliothèque

//Bus
typedef struct{ int barr; int pareB; int blind; int infirm; int cuisine; int couch; int entrepot;}t_modif;
t_modif modif;

typedef struct{ int hp; int degat; int entrepot; int survivant_max; int consoV; int consoS;}t_bus;
t_bus bus;

typedef struct{ int materiaux; int vivre; int soin;}t_inventaire;
t_inventaire inventaire;

typedef struct{ int machette; int hache; int epee; int arc; int arbalete; int pistolet; int mitraillette; int sniper;}t_armebus;
t_armebus inventArme;

//Perso
typedef enum{massue, machette, hache, epee, arc, arbalete, pistolet, mitraillette, sniper}t_arme;

typedef enum{mort, vivant}t_etat;

typedef struct{int hp; int attaque; int nb_materiaux; int nb_soins; int nb_vivres; t_arme arme; t_etat etat; int deplacement; int action;}t_survivant;
t_survivant surv[N];

typedef struct{int hp; int attaque; t_etat etat;}t_zombies;
t_zombies zomb[Z];