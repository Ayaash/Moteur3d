#include "lib_3d.h"
#include "lib_objet3d.h"
#include "lib_scene3d.h"




 t_point3d *(*definirPoint3d)(double x, double y, double z) = definirPoint3d_etu;
 t_point3d *(*definirVecteur3d)(double x, double y, double z) = definirVecteur3d_etu;
 t_triangle3d *(*definirTriangle3d)(t_point3d * a, t_point3d * b, t_point3d * c) = definirTriangle3d_etu;
 t_triangle3d *(*copierTriangle3d)(t_triangle3d *t) = copierTriangle3d_etu;
 void (*differenceVecteur3d)(t_point3d *v1, t_point3d *v2) = differenceVecteur3d_etu;
 void (*sommeVecteur3d)(t_point3d *v1, t_point3d *v2) = sommeVecteur3d_etu;
 void (*divisionVecteur3d)(t_point3d *v1, int n) = divisionVecteur3d_etu;
 t_point3d* (*centreGraviteTriangle3d)(t_triangle3d *t) = centreGraviteTriangle3d_etu;

 double (*zmoyen)(t_triangle3d *t) = zmoyen_etu;
 void (*remplirTriangle3d)(t_surface * surface, t_triangle3d * triangle, Uint32 c, double l, double h, double d) = remplirTriangle3d_etu;

 void (*translationTriangle3d)(t_triangle3d *t, t_point3d *vecteur) = translationTriangle3d_etu;
 void (*rotationTriangle3d)(t_triangle3d *t, t_point3d *centre, float degreX, float degreY, float degreZ) = rotationTriangle3d_etu;
 void (*transformationTriangle3d)(t_triangle3d *t, double mat[4][4]) = transformationTriangle3d_etu;

 t_objet3d* (*objet_vide)() = objet_vide_etu;
 t_objet3d *(*camera)(double l, double h, double n, double f, double d) = camera_etu;
 t_objet3d* (*parallelepipede)(double lx, double ly, double lz) = parallelepipede_etu;
 t_objet3d* (*sphere)(double r, double nlat, double nlong) = sphere_etu;
 t_objet3d* (*sphere_amiga)(double r, double nlat, double nlong) = sphere_amiga_etu;
 t_objet3d* (*arbre)(double lx, double ly, double lz) = arbre_etu;
 t_objet3d* (*damier)(double lx, double lz, double nx, double nz) = damier_etu;
 t_objet3d *(*copierObjet3d)(t_objet3d *o) = copierObjet3d_etu;
 void (*composerObjet3d)(t_objet3d* o, t_objet3d* o2) = composerObjet3d_PA;
 void (*composerObjet3d_limite_en_z)(t_objet3d* o, t_objet3d* o2, t_objet3d *camera) = composerObjet3d_limite_en_z_PA;
 void (*libererObjet3d)(t_objet3d *o) = libererObjet3d_PA;
 t_point3d *(*centreGraviteObjet3d)(t_objet3d *o) = centreGraviteObjet3d_PA;
 void (*dessinerObjet3d)(t_surface *surface, t_objet3d* pt_objet, t_objet3d *camera) = dessinerObjet3d_PA;

 void (*translationObjet3d)(t_objet3d* pt_objet, t_point3d *vecteur) = translationObjet3d_PA;
 void (*translationObjet3d_fast)(t_objet3d* pt_objet, t_point3d *vecteur) = translationObjet3d_fast_PA;
 void (*rotationObjet3d)(t_objet3d* pt_objet, t_point3d *centre, float degreX, float degreY, float degreZ) = rotationObjet3d_PA;
 void (*rotationObjet3d_fast)(t_objet3d* pt_objet, t_point3d *centre, float degreX, float degreY, float degreZ) = rotationObjet3d_fast_PA;
 void (*transformationObjet3d)(t_objet3d* pt_objet, double mat[4][4]) = transformationObjet3d_PA;

 t_scene3d* (*definirScene3d)(t_objet3d *pt_objet) = definirScene3d_PA;
 t_scene3d* (*ajouter_relation)(t_scene3d* pt_feuille, t_objet3d *pt_objet) = ajouter_relation_PA;
 void (*translationScene3d)(t_scene3d *pt_scene, t_point3d *vecteur) = translationScene3d_PA;
 void (*rotationScene3d)(t_scene3d *pt_scene, t_point3d *centre, float degreX, float degreY, float degreZ) = rotationScene3d_PA;
 void (*dessinerScene3d)(t_surface *surface, t_scene3d* pt_scene) = dessinerScene3d_PA;
 void (*changerCamera)(t_scene3d *pt_objet) = changerCamera_PA;

