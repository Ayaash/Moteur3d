#include "lib_3d.h"

t_point3d * definirPoint3d_etu(double x, double y, double z)
{
	t_point3d * ret = (t_point3d*)malloc(sizeof(t_point3d));
	ret->xyzt[0] = x;
	ret->xyzt[1] = y;
	ret->xyzt[2] = z;
	ret->xyzt[3] = 1;
	return ret;
}

t_point3d * definirVecteur3d_etu(double x, double y, double z)
{
	t_point3d * ret = (t_point3d*)malloc(sizeof(t_point3d));
	ret->xyzt[0] = x;
	ret->xyzt[1] = y;
	ret->xyzt[2] = z;
	ret->xyzt[3] = 0;
	return ret;
}

t_triangle3d * definirTriangle3d_etu(t_point3d * a, t_point3d * b, t_point3d * c)
{
	t_triangle3d * p = (t_triangle3d*)malloc(sizeof(t_triangle3d));
	p->abc[0] = a;
	p->abc[1] = b;
	p->abc[2] = c;
	return p;
}

t_triangle3d * copierTriangle3d_etu(t_triangle3d * t)
{
	t_triangle3d * copy = (t_triangle3d*)malloc(sizeof(t_triangle3d));
	copy->abc[0] = definirPoint3d_etu(t->abc[0]->xyzt[0],t->abc[0]->xyzt[1],t->abc[0]->xyzt[2]);
	copy->abc[1] = definirPoint3d_etu(t->abc[1]->xyzt[0],t->abc[1]->xyzt[1],t->abc[1]->xyzt[2]);
	copy->abc[2] = definirPoint3d_etu(t->abc[2]->xyzt[0],t->abc[2]->xyzt[1],t->abc[2]->xyzt[2]);
	return copy;
}

void differenceVecteur3d_etu(t_point3d * v1, t_point3d * v2)
{
	v1->xyzt[0] = v1->xyzt[0] - v2->xyzt[0];
	v1->xyzt[1] = v1->xyzt[1] - v2->xyzt[1];
	v1->xyzt[2] = v1->xyzt[2] - v2->xyzt[2];
}

void sommeVecteur3d_etu(t_point3d * v1, t_point3d * v2)
{
	v1->xyzt[0] = v1->xyzt[0] + v2->xyzt[0];
	v1->xyzt[1] = v1->xyzt[1] + v2->xyzt[1];
	v1->xyzt[2] = v1->xyzt[2] + v2->xyzt[2];
}

void divisionVecteur3d_etu(t_point3d * v1, int n)
{
	v1->xyzt[0] /= n;
	v1->xyzt[1] /= n;
	v1->xyzt[2] /= n;
	v1->xyzt[3] /= n;
}

t_point3d * centreGraviteTriangle3d_etu(t_triangle3d * t)
{
	t_point3d * pplot = (t_point3d*)malloc(sizeof(t_point3d));
	pplot->xyzt[0] = (t->abc[0]->xyzt[0] + t->abc[1]->xyzt[0] + t->abc[2]->xyzt[0])/3;
	pplot->xyzt[1] = (t->abc[0]->xyzt[1] + t->abc[1]->xyzt[1] + t->abc[2]->xyzt[1])/3;
	pplot->xyzt[2] = (t->abc[0]->xyzt[2] + t->abc[1]->xyzt[2] + t->abc[2]->xyzt[2])/3;
	pplot->xyzt[3] = 0;
	return pplot;
}

double zmoyen_etu(t_triangle3d * t)
{
	return (t->abc[0]->xyzt[2] + t->abc[1]->xyzt[2] + t->abc[2]->xyzt[2])/3;
}

void remplirTriangle3d_etu(t_surface * surface, t_triangle3d * triangle, Uint32 c, double l, double h, double d) // FIXME
{
	// Declarations
	t_triangle2d * t2d = NULL;
	t_point2d * pa = NULL;
	t_point2d * pb = NULL;
	t_point2d * pc = NULL;
	double matriceProjection[4][4];
	double vecteurProjete[4];

	// Creation de la matrice de projection
	initialiseMatrice(matriceProjection);
	matriceProjection[0][0] = 1/l;
	matriceProjection[1][1] = 1/h;
	matriceProjection[2][2] = 1/d;
	matriceProjection[3][2] = 1;

	// Calcul du premier point du triangle
	initialiseVecteur(vecteurProjete);
	produitMatriciel(matriceProjection, triangle->abc[0]->xyzt, vecteurProjete);
	pa = definirPoint2d((int)vecteurProjete[0]/vecteurProjete[2] + RX/2, -(int)vecteurProjete[1]/vecteurProjete[2] + RY/2);

	// Calcul du second point du triangle
	initialiseVecteur(vecteurProjete);
	produitMatriciel(matriceProjection, triangle->abc[1]->xyzt, vecteurProjete);
	pb = definirPoint2d((int)vecteurProjete[0]/vecteurProjete[2] + RX/2, -(int)vecteurProjete[1]/vecteurProjete[2] + RY/2);

	// Calcul du troisieme point du triangle
	initialiseVecteur(vecteurProjete);
	produitMatriciel(matriceProjection, triangle->abc[2]->xyzt, vecteurProjete);
	pc = definirPoint2d((int)vecteurProjete[0]/vecteurProjete[2] + RX/2, -(int)vecteurProjete[1]/vecteurProjete[2] + RY/2);

	t2d = definirTriangle2d(pa, pb, pc);
	remplirTriangle2d(surface, t2d, c);
}

void produitMatriciel(double matrice[4][4], double vecteur[4], double vecteurProjete[4])
{
	int i, j;
	for(i=0;i<4;i++)
	{
		vecteurProjete[i] = 0;
		for(j=0;j<4;j++)
		{	
			vecteurProjete[i] += matrice[i][j]*vecteur[j];
		}
	}
}

void initialiseMatrice(double matrice[4][4])
{
	int i, j;
	for(i = 0; i<4;i++)
	{
		for(j=0; j<4; j++)
		{
			matrice[i][j] = 0;
		}
	}
}

void initialiseVecteur(double vecteur[4])
{
	int i;
	for(i=0 ; i<4; i++)
	{
		vecteur[i] = 0;
	}
}

void translationTriangle3d_etu(t_triangle3d * t, t_point3d * vecteur)
{
	sommeVecteur3d_etu(t->abc[0], vecteur);
	sommeVecteur3d_etu(t->abc[1], vecteur);
	sommeVecteur3d_etu(t->abc[2], vecteur);
}

void rotationTriangle3d_etu(t_triangle3d * t,  t_point3d * centre, float degreX, float degreY, float degreZ)
{
	double matriceRotationX[4][4];
	double matriceRotationY[4][4];
	double matriceRotationZ[4][4];
	double vecteurRotation[4];

	// Matrice de rotation selon l'axe X
	initialiseMatrice(matriceRotationX);
	matriceRotationX[0][0] = 1;
	matriceRotationX[1][1] = cos(degreX);
	matriceRotationX[1][2] = -sin(degreX);
	matriceRotationX[2][1] = sin(degreX);
	matriceRotationX[2][2] = cos(degreX);
	matriceRotationX[3][3] = 1;
	
	// Matrice de rotation selon l'axe Y
	initialiseMatrice(matriceRotationY);
	matriceRotationY[0][0] = cos(degreY);
	matriceRotationY[0][2] = -sin(degreY);
	matriceRotationY[1][1] = 1;
	matriceRotationY[2][0] = sin(degreY);
	matriceRotationY[2][2] = cos(degreY);
	matriceRotationY[3][3] = 1;
	
	// Matrice de rotation selon l'axe Z
	initialiseMatrice(matriceRotationZ);
	matriceRotationZ[0][0] = cos(degreZ);
	matriceRotationZ[0][1] = -sin(degreZ);
	matriceRotationZ[1][0] = sin(degreZ);
	matriceRotationZ[1][1] = cos(degreZ);
	matriceRotationZ[2][2] = 1;
	matriceRotationZ[3][3] = 1;

	// On recentre le triangle
	differenceVecteur3d_etu(t->abc[0], centre);
	differenceVecteur3d_etu(t->abc[1], centre);
	differenceVecteur3d_etu(t->abc[2], centre);

	// On effectue la rotation selon X
	produitMatriciel(matriceRotationX, t->abc[0]->xyzt, vecteurRotation);
	t->abc[0]->xyzt[0] = vecteurRotation[0];
	t->abc[0]->xyzt[1] = vecteurRotation[1];
	t->abc[0]->xyzt[2] = vecteurRotation[2];
	t->abc[0]->xyzt[3] = vecteurRotation[3];
	produitMatriciel(matriceRotationX, t->abc[1]->xyzt, vecteurRotation);
	t->abc[1]->xyzt[0] = vecteurRotation[0];
	t->abc[1]->xyzt[1] = vecteurRotation[1];
	t->abc[1]->xyzt[2] = vecteurRotation[2];
	t->abc[1]->xyzt[3] = vecteurRotation[3];
	produitMatriciel(matriceRotationX, t->abc[2]->xyzt, vecteurRotation);
	t->abc[2]->xyzt[0] = vecteurRotation[0];
	t->abc[2]->xyzt[1] = vecteurRotation[1];
	t->abc[2]->xyzt[2] = vecteurRotation[2];
	t->abc[2]->xyzt[3] = vecteurRotation[3];
	
	// On effectue la rotation selon Y
	produitMatriciel(matriceRotationY, t->abc[0]->xyzt, vecteurRotation);
	t->abc[0]->xyzt[0] = vecteurRotation[0];
	t->abc[0]->xyzt[1] = vecteurRotation[1];
	t->abc[0]->xyzt[2] = vecteurRotation[2];
	t->abc[0]->xyzt[3] = vecteurRotation[3];
	produitMatriciel(matriceRotationY, t->abc[1]->xyzt, vecteurRotation);
	t->abc[1]->xyzt[0] = vecteurRotation[0];
	t->abc[1]->xyzt[1] = vecteurRotation[1];
	t->abc[1]->xyzt[2] = vecteurRotation[2];
	t->abc[1]->xyzt[3] = vecteurRotation[3];
	produitMatriciel(matriceRotationY, t->abc[2]->xyzt, vecteurRotation);
	t->abc[2]->xyzt[0] = vecteurRotation[0];
	t->abc[2]->xyzt[1] = vecteurRotation[1];
	t->abc[2]->xyzt[2] = vecteurRotation[2];
	t->abc[2]->xyzt[3] = vecteurRotation[3];

	// On effectue la rotation selon Z
	produitMatriciel(matriceRotationZ, t->abc[0]->xyzt, vecteurRotation);
	t->abc[0]->xyzt[0] = vecteurRotation[0];
	t->abc[0]->xyzt[1] = vecteurRotation[1];
	t->abc[0]->xyzt[2] = vecteurRotation[2];
	t->abc[0]->xyzt[3] = vecteurRotation[3];
	produitMatriciel(matriceRotationZ, t->abc[1]->xyzt, vecteurRotation);
	t->abc[1]->xyzt[0] = vecteurRotation[0];
	t->abc[1]->xyzt[1] = vecteurRotation[1];
	t->abc[1]->xyzt[2] = vecteurRotation[2];
	t->abc[1]->xyzt[3] = vecteurRotation[3];
	produitMatriciel(matriceRotationZ, t->abc[2]->xyzt, vecteurRotation);
	t->abc[2]->xyzt[0] = vecteurRotation[0];
	t->abc[2]->xyzt[1] = vecteurRotation[1];
	t->abc[2]->xyzt[2] = vecteurRotation[2];
	t->abc[2]->xyzt[3] = vecteurRotation[3];

	// On retranslate le triangle
	sommeVecteur3d_etu(t->abc[0], centre);
	sommeVecteur3d_etu(t->abc[1], centre);
	sommeVecteur3d_etu(t->abc[2], centre);
}

void transformationTriangle3d_etu(t_triangle3d * t, double mat[4][4])
{
	double vecteurRotation[4];

	produitMatriciel(mat, t->abc[0]->xyzt, vecteurRotation);
	t->abc[0]->xyzt[0] = vecteurRotation[0];
	t->abc[0]->xyzt[1] = vecteurRotation[1];
	t->abc[0]->xyzt[2] = vecteurRotation[2];
	t->abc[0]->xyzt[3] = vecteurRotation[3];
	produitMatriciel(mat, t->abc[1]->xyzt, vecteurRotation);
	t->abc[1]->xyzt[0] = vecteurRotation[0];
	t->abc[1]->xyzt[1] = vecteurRotation[1];
	t->abc[1]->xyzt[2] = vecteurRotation[2];
	t->abc[1]->xyzt[3] = vecteurRotation[3];
	produitMatriciel(mat, t->abc[2]->xyzt, vecteurRotation);
	t->abc[2]->xyzt[0] = vecteurRotation[0];
	t->abc[2]->xyzt[1] = vecteurRotation[1];
	t->abc[2]->xyzt[2] = vecteurRotation[2];
	t->abc[2]->xyzt[3] = vecteurRotation[3];
}
