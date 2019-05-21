#include <stdio.h>
#include <stdlib.h>
#include "libgraphique.h"
#include <time.h>
#define cote (1.5*WINDOW_WIDTH/2.5)/5
#define p_cote cote/2.2
#include <windows.h>

int x_case(int n) //Renvoie la coordonné x du coin supérieur gauche de la case numéro n
{
    if(n==1 || n==3) return cote;
    if(n==5) return 2*cote;
    if(n==2 || n==4) return 3*cote;
    if(n>=6 && n<=10) return p_cote+(n-6)*2*p_cote;
}

int y_case(int n) //Renvoie la coordonné y du coin supérieur gauche de la case numéro n
{
    if(n==1 || n==2) return 4*WINDOW_HEIGHT/5;
    if(n==3 || n==4) return 4*WINDOW_HEIGHT/5-1.5*cote;
    if(n==5) return 4*WINDOW_HEIGHT/5-3*cote;
    if(n>=6 && n<=10) return WINDOW_HEIGHT/5/3;
}

int x_result()
{
    return 2.37*WINDOW_WIDTH/2.48;
}

int y_result(int n)
{
    return ((18-n)*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5);
}

void dessin_case(int p) //p : position du dé à dessiner
{
    if(p>=1 && p<=5) draw_rectangle(x_case(p),y_case(p),x_case(p)+cote,y_case(p)+cote);
    if(p>=6 && p<=10) draw_rectangle(x_case(p),y_case(p),x_case(p)+p_cote,y_case(p)+p_cote);
}

void dessin_points(int p, int c) //p: nombre de points à dessiner | c: numéro de la case remplie
{
    int r,t;
    if(c>=1 && c<=5) t=cote;
    if(c>=6 && c<=10) t=p_cote;
    r=t/9;
    if(p==1) draw_circle_full(x_case(c)+t/2,y_case(c)+t/2,r);
    if(p==2)
    {
        draw_circle_full(x_case(c)+t/4,y_case(c)+t/4,r);
        draw_circle_full(x_case(c)+3*t/4,y_case(c)+3*t/4,r);
    }
    if(p==3)
    {
        draw_circle_full(x_case(c)+t/2,y_case(c)+t/2,r);
        draw_circle_full(x_case(c)+t/4,y_case(c)+t/4,r);
        draw_circle_full(x_case(c)+3*t/4,y_case(c)+3*t/4,r);
    }
    if(p==4)
    {
        draw_circle_full(x_case(c)+t/4,y_case(c)+3*t/4,r);
        draw_circle_full(x_case(c)+3*t/4,y_case(c)+t/4,r);
        draw_circle_full(x_case(c)+t/4,y_case(c)+t/4,r);
        draw_circle_full(x_case(c)+3*t/4,y_case(c)+3*t/4,r);
    }
    if(p==5)
    {
        draw_circle_full(x_case(c)+t/2,y_case(c)+t/2,r);
        draw_circle_full(x_case(c)+t/4,y_case(c)+3*t/4,r);
        draw_circle_full(x_case(c)+3*t/4,y_case(c)+t/4,r);
        draw_circle_full(x_case(c)+t/4,y_case(c)+t/4,r);
        draw_circle_full(x_case(c)+3*t/4,y_case(c)+3*t/4,r);
    }
    if(p==6)
    {
        draw_circle_full(x_case(c)+t/4,y_case(c)+t/2,r);
        draw_circle_full(x_case(c)+3*t/4,y_case(c)+t/2,r);
        draw_circle_full(x_case(c)+t/4,y_case(c)+3*t/4,r);
        draw_circle_full(x_case(c)+3*t/4,y_case(c)+t/4,r);
        draw_circle_full(x_case(c)+t/4,y_case(c)+t/4,r);
        draw_circle_full(x_case(c)+3*t/4,y_case(c)+3*t/4,r);
    }
}

void dessin_de(int position, int point)
{
    dessin_case(position);
    dessin_points(point,position);
}

void init_screen()
{
    draw_line(1.5*WINDOW_WIDTH/2.5,WINDOW_HEIGHT,1.5*WINDOW_WIDTH/2.5,0);
    draw_line(0,WINDOW_HEIGHT/5,WINDOW_WIDTH,WINDOW_HEIGHT/5);
    set_font(font_HELVETICA_18);
    draw_printf(1.5*WINDOW_WIDTH/2.48,(17*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"UN ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(16*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"DEUX ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(15*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"TROIS ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(14*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"QUATRE ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(13*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"CINQ ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(12*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"SIX ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(11*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"Total >=63 ?");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(9*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"Brelan ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(8*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"Carre  ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(7*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"Full  ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(6*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"Petite suite  ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(5*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"Grande suite ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(4*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"Yams ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(3*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"Chance  ");
    draw_printf(1.5*WINDOW_WIDTH/2.48,(1*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"Total Global ");

    set_font(font_HELVETICA_12);
    draw_printf(2*WINDOW_WIDTH/2.48,(17*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[Total UN] ");
    draw_printf(2*WINDOW_WIDTH/2.48,(16*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[Total DEUX] ");
    draw_printf(2*WINDOW_WIDTH/2.48,(15*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[Total TROIS] ");
    draw_printf(2*WINDOW_WIDTH/2.48,(14*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[Total QUATRE] ");
    draw_printf(2*WINDOW_WIDTH/2.48,(13*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[Total CINQ] ");
    draw_printf(2*WINDOW_WIDTH/2.48,(12*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[Total SIX] ");
    draw_printf(2*WINDOW_WIDTH/2.48,(11*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[35 pts]");
    draw_printf(2*WINDOW_WIDTH/2.48,(9*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[Total DES] ");
    draw_printf(2*WINDOW_WIDTH/2.48,(8*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[Total DES]  ");
    draw_printf(2*WINDOW_WIDTH/2.48,(7*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[25 pts]");
    draw_printf(2*WINDOW_WIDTH/2.48,(6*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[30 pts]  ");
    draw_printf(2*WINDOW_WIDTH/2.48,(5*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[40 pts] ");
    draw_printf(2*WINDOW_WIDTH/2.48,(4*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[50 pts] ");
    draw_printf(2*WINDOW_WIDTH/2.48,(3*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"[Total DES] ");
    update_graphics();
    update_graphics();
}

void clear_part(int n) //n: numéro de la partie à effacer
{
    set_drawing_color(color_WHITE);
    if(n==4) draw_rectangle_full(1.5*WINDOW_WIDTH/2.5+1,WINDOW_HEIGHT/5-1,WINDOW_WIDTH,0);
    if(n==3) draw_rectangle_full(0,WINDOW_HEIGHT/5-1,1.5*WINDOW_WIDTH/2.5-1,0);
    if(n==1) draw_rectangle_full(0,WINDOW_HEIGHT/5+1,1.5*WINDOW_WIDTH/2.5-1,WINDOW_HEIGHT);
    set_drawing_color(color_BLACK);
    update_graphics();
}

void init_lance()
{
    clear_part(4);
    clear_part(1);
    set_font(font_HELVETICA_18);
    draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/2,"Lancez les des !!!");
    draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/4,"Appuyez sur une touche");
    update_graphics();
    get_key();
    clear_part(4);
    update_graphics();
}

void lance(int m[]) //d: nombre de dés à lancer | t: mémorisation des dés lancés | m: mémorisation des dés conservés
{
    int k,i,j,compt3=1,compt2=0;
    do
    {
        int compt;
        compt2=0;
        clear_part(4);
        clear_part(1);
        compt3++; //Compte le nombre de lancés
        for(i=0;i<=25;i++) //Nombre de faces qui s'affichent lors du lancé
        {
            for(j=1;j<=5;j++) //Pour 5 dés
            {
                if(m[j]==0){ //Lance seulement les dés non mémorisés ou jamais lancés
                dessin_de(j,i%6+1); //Affiche les faces de 1 à 6, tour après tour
                }
            }
            update_graphics();
            Sleep(60);
            clear_part(1);
        }
        printf("\n");
        printf("\n");
        for(j=1;j<=5;j++) // Pour un maximum de 5 dés à lancer
        {
            if(m[j]==0){ //Si un dé n'a pas été choisi d'être mémorisé ou n'a jamais été lancé
            m[j]=rand()%6+1; //Choisis une valeur aléatoire entre 1 et 6
            dessin_de(j,m[j]);
            }
            printf("%d - ",m[j]);
        }

        /*if(compt3==4)
        {
            draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/2,"Vous avez lance 3 fois !");
            draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/4,"Appuyez Entree pour continuer");
            update_graphics();
            get_key();
        }*/
        if (compt3!=4) do{
        draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/2,"Choisissez resultats a relancer");
        draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/4,"(Entree pour continuer/arreter)");
        update_graphics();
        k=get_key();
        if(k!=13){
        compt=0;
        for(j=1;j<=5;j++)
        {
            if(m[j]==k-48)
            {
                m[j]=0;
                set_drawing_color(color_WHITE);
                draw_rectangle_full(x_case(j+5),y_case(j+5),x_case(j+5)+p_cote,y_case(j+5)+p_cote);
                draw_rectangle_full(x_case(j),y_case(j),x_case(j)+cote,y_case(j)+cote);
                set_drawing_color(color_BLACK);
                compt++; //Compte le nombre de passages dans la boucle, donc si le résultat existe dans les dés lancés
                j=6; //Pour que la détection d'un bon chiffre arrete la boucle et n'en choisisse pas plusieurs identiques
            }
        }
        compt2++; //Compte le nombre de dés à relancer. Si 0, les lancers s'arrêtent
        if(compt==0)
        {
            clear_part(4);
            draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/2,"MAUVAIS CHIFFRE !");
            draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/4,"Appuyez une touche pour continuer");
            update_graphics();
            get_key();
            clear_part(4);
            compt2=0;
        }
        }
        }
        while(k!=13);
        for(j=1;j<=5;j++)
        {
            if(m[j]!=0)
            {
                dessin_de(j+5,m[j]);
            }
        }
        printf("\n");
        for(j=1;j<=5;j++)
        {
            printf("%d - ",m[j]);
        }
    }
    while (compt2!=0);
}

int test_chiffre(int m[], int c)
{
    int j,score=0;
    for(j=1;j<=5;j++)
        {
            if(m[j]==c) score++;
        }
    return c*score;
}

int test_suite(int m[], int t)
{
    int j;
    if(t==1) // 1=Petite Suite
    {
        for(j=1;j<=5;j++) {if(m[j]==1) for(j=1;j<=5;j++) {if(m[j]==2) for(j=1;j<=5;j++) {if(m[j]==3) for(j=1;j<=5;j++) {if(m[j]==4) return 30;}}}}
        for(j=1;j<=5;j++) {if(m[j]==2) for(j=1;j<=5;j++) {if(m[j]==3) for(j=1;j<=5;j++) {if(m[j]==4) for(j=1;j<=5;j++) {if(m[j]==5) return 30;}}}}
        for(j=1;j<=5;j++) {if(m[j]==3) for(j=1;j<=5;j++) {if(m[j]==4) for(j=1;j<=5;j++) {if(m[j]==5) for(j=1;j<=5;j++) {if(m[j]==6) return 30;}}}}
    }
    if(t==2) // 2=Grande Suite
    {
        for(j=1;j<=5;j++) {if(m[j]==1) for(j=1;j<=5;j++) {if(m[j]==2) for(j=1;j<=5;j++) {if(m[j]==3) for(j=1;j<=5;j++) {if(m[j]==4) for(j=1;j<=5;j++) {if(m[j]==5) return 40;}}}}}
        for(j=1;j<=5;j++) {if(m[j]==2) for(j=1;j<=5;j++) {if(m[j]==3) for(j=1;j<=5;j++) {if(m[j]==4) for(j=1;j<=5;j++) {if(m[j]==5) for(j=1;j<=5;j++) {if(m[j]==6) return 40;}}}}}
    }
    return 0;
}

int test_brelan_carre(int m[], int t) //Avec t=3 pour le brelan ; t=4 pour le carre
{
    int i,j,compt;
    for(i=1;i<=6;i++)
    {
        compt=0;
        for(j=1;j<=5;j++)
        {
            if(m[j]==i) compt++;
        }
        if(compt>=t) return m[1]+m[2]+m[3]+m[4]+m[5];
    }
    return 0;
}

int test_full(int m[])
{
    int j,i,l,compt;
    for(i=1;i<=6;i++)
    {
        compt=0;
        for(j=1;j<=5;j++)
        {
            if(m[j]==i) compt++;
        }
        if(compt>=2)
        {
            for(l=1;l<=6;l++)
            {
                compt=0;
                for(j=1;j<=5;j++)
                {
                    if(m[j]==l && l!=i) compt++;
                }
                if(compt>=3) return 25;
            }
        }
    }
    return 0;
}

int test_yams(int m[])
{
    int i,j,compt;
    for(i=1;i<=6;i++)
    {
        compt=0;
        for(j=1;j<=5;j++)
        {
            if(m[j]==i) compt++;
        }
        if(compt==5) return 50;
    }
    return 0;
}

int test_chance(int m[])
{
    return m[1]+m[2]+m[3]+m[4]+m[5];
}

int test_bonus(int s[])
{
    int compt=0,j;
    for(j=1;j<=6;j++)
    {
        if(s[j]==-1) return -1;
        compt+=s[j];
    }
    if (compt>=63) return 35;
    return 0;
}

int test_fin(int r[])
{
    int j,compt=0;
    for(j=1;j<=13;j++)
    {
        if(r[j]==-1) return -1;
        compt+=r[j];
    }
    return compt;
}

void init_tab(int t[], int n)
{
    int j;
    for(j=1;j<=17;j++)
        {
            t[j]=n;
        }
}

int choix_score()
{
    int x;
    clear_part(4);
    clear_part(1);
    set_font(font_HELVETICA_18);
    draw_printf(WINDOW_WIDTH/2.2,(17*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"1 ---->");
    draw_printf(WINDOW_WIDTH/2.2,(16*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"2 ---->");
    draw_printf(WINDOW_WIDTH/2.2,(15*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"3 ---->");
    draw_printf(WINDOW_WIDTH/2.2,(14*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"4 ---->");
    draw_printf(WINDOW_WIDTH/2.2,(13*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"5 ---->");
    draw_printf(WINDOW_WIDTH/2.2,(12*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"6 ---->");
    draw_printf(WINDOW_WIDTH/2.2,(9*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"B ---->");
    draw_printf(WINDOW_WIDTH/2.2,(8*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"C ---->");
    draw_printf(WINDOW_WIDTH/2.2,(7*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"F ---->");
    draw_printf(WINDOW_WIDTH/2.2,(6*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"P ---->");
    draw_printf(WINDOW_WIDTH/2.2,(5*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"G ---->");
    draw_printf(WINDOW_WIDTH/2.2,(4*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"Y ---->");
    draw_printf(WINDOW_WIDTH/2.2,(3*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"H ---->");
    draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/2,"Choisissez la ligne a scorer");
    draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/4,"au clavier");
    update_graphics();
    x=get_key();
    return x;

}

int test(int m[], int n, int r[])
{
    int i;
    for(i=1;i<=6;i++)
    {
        if(i==n-48 && r[i]==-1) return test_chiffre(m,i);
    }
    if(n==98 && r[7]==-1) return test_brelan_carre(m,3);
    if(n==99 && r[8]==-1) return test_brelan_carre(m,4);
    if(n==102 && r[9]==-1) return test_full(m);
    if(n==112 && r[10]==-1) return test_suite(m,1);
    if(n==103 && r[11]==-1) return test_suite(m,2);
    if(n==121 && r[12]==-1) return test_yams(m);
    if(n==104 && r[13]==-1) return test_chance(m);
    clear_part(4);
    draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/2,"MAUVAISE TOUCHE !");
    draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/4,"Appuyez une touche pour continuer");
    update_graphics();
    get_key();
    return -1;
}

int rec(int r[], int s[], int x, int y)
{
    int i;
    if(x>=49 && x<=54) x=x-48;
    if(x==98 || x==99) x=x-91;
    if(x==102) x=x-93;
    if(x==112) x=x-102;
    if(x==103) x=x-92;
    if(x==121) x=x-109;
    if(x==104) x=x-91;
    if (x<=6) draw_printf(2.38*WINDOW_WIDTH/2.48,((18-x)*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"%d",y);
    if(x>=7 && x<=13) draw_printf(2.39*WINDOW_WIDTH/2.48,((16-x)*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"%d",y);
    update_graphics();
    for(i=1;i<=13;i++)
    {
        if(x==i)
        {
            if(x<=6) s[x]=y;
            r[x]=y;
        }
    }
    y=test_bonus(s);
    if(y!=-1)
    {
        draw_printf(2.38*WINDOW_WIDTH/2.48,(11*(4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"%d",y);
        update_graphics();
        r[14]=y;
    }
    y=test_fin(r);
    if(y!=-1)
    {
        draw_printf(2.38*WINDOW_WIDTH/2.48,((4*WINDOW_HEIGHT/5)/18)+(WINDOW_HEIGHT/5),"%d",y);
        update_graphics();
        r[15]=y;
        return 1;
    }
    return 0;
}

int rec_fichier(FILE *f, int r[])
{
    int x,compt=1;
    clear_part(4);
    clear_part(1);
    clear_part(3);
    draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/2,"Saisissez votre nom au clavier");
    draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/4,"(Entree pour confirmer)");
    update_graphics();
    fprintf(f,"\nSCORE de ");
    do
    {
        x=get_key();
        draw_printf((0.02*compt)*WINDOW_WIDTH+(1/5)*WINDOW_WIDTH,((WINDOW_HEIGHT/5)/2),"%c",x-32);
        update_graphics();
        if(x!=13) fprintf(f,"%c",x-32);
        compt++;
    }
    while(x!=13 && compt!=12);
    fprintf(f," : %d\n",test_fin(r));
}

int main()
{
    srand(time(0));
    int m[6], r[16], s[7],x,y=-1,z;
    FILE *f;
    start_graphics();
    init_tab(r,-1);
    init_tab(s,-1);
    init_screen();
    do
    {
        clear_part(3);
        init_tab(m,0);
        init_lance();
        lance(m);
        do
        {
            x=choix_score(r);
            y=test(m,x,r);
        }
        while (y==-1);
        z=rec(r,s,x,y);
    }
    while(z!=1);
    clear_part(4);
    draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/2,"PARTIE TERMINEE !");
    draw_printf(1.5*WINDOW_WIDTH/2.48,WINDOW_HEIGHT/5/4,"Appuyez une touche pour continuer");
    update_graphics();
    get_key();
    f=fopen("resultats.txt","a");
    if(f==NULL)
	{
		printf("Erreur dans l'ouverture du fichier 1");
		exit(1);
	}
	rec_fichier(f,r);
	fclose(f);
    stop_graphics();
    return 0;
}
