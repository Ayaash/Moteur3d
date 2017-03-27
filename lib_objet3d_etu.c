#include "lib_objet3d.h"

Uint32 randomColor()
{
	int x = rand() % 20;
	switch(x)
	{
		case 0:
			return BLANC;
		case 1:
			return GRISC;
		case 2:
			return GRISF;
		case 3:
			return NOIR;
		case 4:
			return ROUGEC;
		case 5:
			return ROUGEF;
		case 6:
			return VERTC;
		case 7:
			return VERTF;
		case 8:
			return BLEUC;
		case 9:
			return BLEUF;
		case 10:
			return JAUNEC;
		case 11:
			return JAUNEF;
		case 12:
			return PALEC;
		case 13:
			return PALEF;
		case 14:
			return ROSEC;
		case 15:
			return ROSEF;
		case 16:
			return MARRON1;
		case 17:
			return MARRON2;
		case 18:
			return MARRON3;
		case 19:
			return MARRON4;
	}
}

t_objet3d *  objet_vide_etu()
{
	t_objet3d * ret = (t_objet3d *)malloc(sizeof(t_objet3d));
	ret->est_trie = false;
	ret->est_camera = false;
	ret->largeur = 0;					// Not necessary
	ret->hauteur = 0;					// Not necessary
	ret->proche = 0;					// Not necessary
	ret->loin = 0;						// Not necessary
	ret->distance_ecran = 0;	// Not necessary
	ret->tete = NULL;

	return ret;
}

t_objet3d * camera_etu(double l, double h, double n, double f, double d)
{
	t_objet3d * ret = (t_objet3d *) malloc(sizeof(t_objet3d));

	ret->est_trie = false;
	ret->est_camera = true;
	ret->largeur = l;
	ret->hauteur = h;
	ret->proche = n;
	ret->loin = f;
	ret->distance_ecran = d;
	ret->tete = NULL; // Not necessary

	return ret;
}

t_objet3d * parallelepipede_etu(double lx, double ly, double lz)
{
	t_point3d *avbg, *avbd, *avhg, *avhd, *arbg, *arbd, *arhg, *arhd;
	t_triangle3d *av1, *av2, *g1, *g2, *d1, *d2, *ar1, *ar2, *h1, *h2, *b1, *b2;

	t_objet3d *parallelepipede = objet_vide();
	t_maillon *maillon;

	// Définition des points
	avbg = definirPoint3d(-lx/2, -ly/2, -lz/2);
	avbd = definirPoint3d(lx/2 , -ly/2, -lz/2);
	avhg = definirPoint3d(-lx/2, ly/2 , -lz/2);
	avhd = definirPoint3d(lx/2 , ly/2 , -lz/2);
	arbg = definirPoint3d(-lx/2, -ly/2, lz/2 );
	arbd = definirPoint3d(lx/2 , -ly/2, lz/2 );
	arhg = definirPoint3d(-lx/2, ly/2 , lz/2 );
	arhd = definirPoint3d(lx/2 , ly/2 , lz/2 );

	// Définition des triangles
	av1 = definirTriangle3d(avbg, avbd, avhd);
	av2 = definirTriangle3d(avbg, avhg, avhd);
	ar1 = definirTriangle3d(arbg, arbd, arhd);
	ar2 = definirTriangle3d(arbg, arhg, arhd);
	g1  = definirTriangle3d(avbg, arbg, avhg);
	g2  = definirTriangle3d(arhg, arbg, avhg);
	d1  = definirTriangle3d(avbd, arbd, avhd);
	d2  = definirTriangle3d(arhd, arbd, avhd);
	h1  = definirTriangle3d(avhg, avhd, arhd);
	h2  = definirTriangle3d(avhg, arhg, arhd);
	b1  = definirTriangle3d(avbg, avbd, arbd);
	b2  = definirTriangle3d(avbg, arbg, arbd);

	// Ajout des triangles à l'objet sous forme de maillons.
	// Les couleurs sont arbitraires
	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = av1;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = av2;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = ar1;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = ar2;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = g1;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = g2;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = d1;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = d2;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = h1;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = h2;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = b1;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	maillon = (t_maillon*) malloc(sizeof(t_maillon));
	maillon->face = b2;
	maillon->couleur = randomColor();
	maillon->pt_suiv = parallelepipede->tete;
	parallelepipede->tete = maillon;

	return parallelepipede;
}

t_objet3d * sphere_etu(double r, double nlat, double nlong)
{
	int i, j;
	t_point3d *pts[(int)nlat][(int)nlong];
	t_triangle3d *triangles[(int)nlat-1][(int)nlong*2];

	t_objet3d *sphere = objet_vide();
	t_maillon *maillon;

	// Définition des points
	for(i = 0; i < nlat; i++)
	{
		for(j = 0; j < nlong; j++)
		{
			pts[i][j] = definirPoint3d(r*sin(pi*i/(nlat))*cos(2*pi*j/nlong ), r*sin(pi*i/(nlat))*sin(2*pi*j/nlong), r*cos(pi*i/(nlat)));
		}
	}

	// Définition des triangles
	for(i = 0; i < nlat-1; i++)
	{
		for(j = 0; j < nlong-1; j++)
		{
			triangles[i][2*j] = definirTriangle3d(pts[i+1][j], pts[i+1][j+1], pts[i][j+1]);
			triangles[i][2*j+1] = definirTriangle3d(pts[i+1][j], pts[i][j], pts[i][j+1]);
		}
		triangles[i][2*(int)nlong-2] = definirTriangle3d(pts[i+1][(int)nlong-1], pts[i+1][0], pts[i][0]);
		triangles[i][2*(int)nlong-1] = definirTriangle3d(pts[i+1][(int)nlong-1], pts[i][(int)nlong-1], pts[i][0]);
	}

	// Ajout des triangles  à l'objet sous forme de maillons
	// Les couleurs sont arbitraires
	for(i = 0; i < nlat-1; i++)
	{
		for(j = 0; j < nlong*2; j++)
		{
			maillon = (t_maillon *) malloc(sizeof(t_maillon));
			maillon->face = triangles[i][j];
			maillon->pt_suiv = sphere->tete;
			sphere->tete = maillon;

			maillon->couleur = randomColor();
		}
	}

	return sphere;
}

t_objet3d * sphere_amiga_etu(double r, double nlat, double nlong)
{
	int i, j;
	t_point3d *pts[(int)nlat][(int)nlong];
	t_triangle3d *triangles[(int)nlat-1][(int)nlong*2];

	t_objet3d *sphere = objet_vide();
	t_maillon *maillon;

	// Définition des points
	for(i = 0; i < nlat; i++)
	{
		for(j = 0; j < nlong; j++)
		{
			pts[i][j] = definirPoint3d(r*sin(pi*i/(nlat))*cos(2*pi*j/nlong ), r*sin(pi*i/(nlat))*sin(2*pi*j/nlong), r*cos(pi*i/(nlat)));	// FIXME PLEASE
		}
	}

	// Définition des triangles
	for(i = 0; i < nlat-1; i++)
	{
		for(j = 0; j < nlong-1; j++)
		{
			triangles[i][2*j] = definirTriangle3d(pts[i+1][j], pts[i+1][j+1], pts[i][j+1]);
			triangles[i][2*j+1] = definirTriangle3d(pts[i+1][j], pts[i][j], pts[i][j+1]);
		}
		triangles[i][2*(int)nlong-2] = definirTriangle3d(pts[i+1][(int)nlong-1], pts[i+1][0], pts[i][0]);
		triangles[i][2*(int)nlong-1] = definirTriangle3d(pts[i+1][(int)nlong-1], pts[i][(int)nlong-1], pts[i][0]);
	}

	// Ajout des triangles à l'objet sous forme de maillons
	for(i = 0; i < nlat-1; i++)
	{
		for(j = 0; j < nlong*2; j++)
		{
			maillon = (t_maillon *) malloc(sizeof(t_maillon));
			maillon->face = triangles[i][j];
			maillon->pt_suiv = sphere->tete;
			sphere->tete = maillon;

			if((i+j/2)%2 == 0)
				maillon->couleur = ROUGEC;
			else
				maillon->couleur = BLANC;
		}
	}

	return sphere;
}

t_objet3d* arbre_etu(double lx, double ly, double lz)
{
	int i;
	t_objet3d *arbre = objet_vide();
	t_maillon * maillon;
	t_point3d *pts[8];
	t_point3d *sommet;
	t_triangle3d *triangles_tronc[8];
	t_triangle3d *triangles_sommet[4];

	// Définition des points
	pts[0] = definirPoint3d(-lx/2, -ly/2, -lz/2);
	pts[1] = definirPoint3d( lx/2, -ly/2, -lz/2);
	pts[2] = definirPoint3d( lx/2, -ly/2,  lz/2);
	pts[3] = definirPoint3d(-lx/2, -ly/2,  lz/2);
	pts[4] = definirPoint3d(-lx/2,  ly/2, -lz/2);
	pts[5] = definirPoint3d( lx/2,  ly/2, -lz/2);
	pts[6] = definirPoint3d( lx/2,  ly/2,  lz/2);
	pts[7] = definirPoint3d(-lx/2,  ly/2,  lz/2);
	sommet = definirPoint3d(0, 0.7*ly, 0);

	// Definition des triangles
	for(i = 0; i < 3; i++)
	{
		triangles_tronc[2*i] = definirTriangle3d(pts[i], pts[i+4], pts[i+5]);
		triangles_tronc[2*i+1] = definirTriangle3d(pts[i], pts[i+1], pts[i+5]);
		triangles_sommet[i] = definirTriangle3d(pts[i+4], pts[i+5], sommet);
	}
	triangles_tronc[6] = definirTriangle3d(pts[3], pts[7], pts[4]);
	triangles_tronc[7] = definirTriangle3d(pts[3], pts[0], pts[4]);
	triangles_sommet[3] = definirTriangle3d(pts[7], pts[0], sommet);

	// Ajout des triangles du tronc à l'objet sous forme de maillons
	for(i = 0; i < 8; i++)
	{
		maillon = (t_maillon *) malloc(sizeof(t_maillon));
		maillon->face = triangles_tronc[i];
		switch (i%4) 
		{
			case 1:
				maillon->couleur = MARRON1;
				break;
			case 2:
				maillon->couleur = MARRON2;
				break;
			case 3:
				maillon->couleur = MARRON3;
				break;
			default:
				maillon->couleur = MARRON4;
		}
		maillon->pt_suiv = arbre->tete;
		arbre->tete = maillon;
	}

	// Ajout des triangles du sommet à l'objet sous forme de maillons
	for(i = 0; i < 4; i++)
	{
		maillon = (t_maillon *) malloc(sizeof(t_maillon));
		maillon->face = triangles_sommet[i];
		maillon->couleur = VERTF;
		maillon->pt_suiv = arbre->tete;
		arbre->tete = maillon;
	}

	return arbre;
}

t_objet3d* damier_etu(double lx, double lz, double nx, double nz)
{
	int i, j, k;
	t_objet3d* damier = objet_vide();
	t_maillon* maillon;
	t_point3d* pts[(int)nx+1][(int)nz+1];
	t_triangle3d* triangles[(int)nx][(int)nz][2];

	// Définition des points
	for(i = 0; i < nx+1; i++)
	{
		for(j = 0; j < nz+1; j++)
		{
			pts[i][j] = definirPoint3d(-lx/2 + i*lx/nx, 0, -lz/2 + j*lz/nz);
		}
	}

	// Définition des triangles
	for(i = 0; i < nx; i++)
	{
		for(j = 0; j < nz; j++)
		{
			triangles[i][j][0] = definirTriangle3d(pts[i][j], pts[i+1][j], pts[i+1][j+1]);
			triangles[i][j][1] = definirTriangle3d(pts[i][j], pts[i][j+1], pts[i+1][j+1]);
		}
	}

	// Ajout des triangles à l'objet sous la forme de maillon
	for(i = 0; i < nx; i++)
	{
		for(j = 0; j < nz; j++)
		{
			for(k = 0; k < 2; k++)
			{
				maillon = (t_maillon *) malloc(sizeof(t_maillon));
				maillon->face = triangles[i][j][k];

				if((i+j)%2 == 0)
					maillon->couleur = NOIR;
				else
					maillon->couleur = BLANC;

				maillon->pt_suiv = damier->tete;
				damier->tete = maillon;
			}
		}
	}

	return damier;
}

t_objet3d *  copierObjet3d_etu(t_objet3d * o) //FIXME!
{
	// Initialisation du nouvel objet
	t_objet3d * copy;
	copy = (t_objet3d *) malloc(sizeof(t_objet3d));
	t_maillon * tete = o->tete;
	t_maillon * nmaillon;

	// Copie des attributs
	copy->est_trie = o->est_trie;
	copy->est_camera = o->est_camera;
	copy->tete = NULL;
	if(copy->est_camera) 
	{
		copy->largeur = o->largeur;
		copy->hauteur = o->hauteur;
		copy->proche = o->proche;
		copy->loin = o->loin;
		copy->distance_ecran = o->distance_ecran;
	}
	else 
	{
		while(tete != NULL) 
		{
			nmaillon = (t_maillon *) malloc(sizeof(t_maillon));
			nmaillon->face = copierTriangle3d(tete->face);
			nmaillon->couleur = tete->couleur;
			nmaillon->pt_suiv = copy->tete;
			copy->tete = nmaillon;
			tete = tete->pt_suiv;
		}
	}
	return copy;
}
