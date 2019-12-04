/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
/* exec sql begin declare section */
     
     
     
     

#line 2 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char STREET_NAME [ 256 ] ;
 
#line 3 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char TRAFFIC [ 256 ] ;
 
#line 4 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char CITY_NAME_2 [ 256 ] ;
 
#line 5 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char DISTRICT_NAME_2 [ 256 ] ;
/* exec sql end declare section */
#line 6 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"


/* exec sql whenever sqlerror  sqlprint ; */
#line 8 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"


int ReadStreetTable();
int UpdateStreetTable();
int InsertStreetTable();
int DeleteStreetTable();
int SelectStreetTable();

void error1();
void error2();
void error3();

void readStringFromConsole(char str[256]);

int ReadStreetTable() {
    printf("Таблица улиц \n");
	printf("%s \t %s \t %s \t %s \n", "Название улицы", "Движение", "Название города", "Название района");
	printf("______________________________________________________________________________________________________________\n");
    /* declare MyCursor cursor for select coalesce ( STREET_NAME , '' ) , coalesce ( TRAFFIC , '' ) , coalesce ( CITY_NAME_2 , '' ) , coalesce ( DISTRICT_NAME_2 , '' ) from STREET order by STREET_NAME */
#line 27 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for select coalesce ( STREET_NAME , '' ) , coalesce ( TRAFFIC , '' ) , coalesce ( CITY_NAME_2 , '' ) , coalesce ( DISTRICT_NAME_2 , '' ) from STREET order by STREET_NAME", ECPGt_EOIT, ECPGt_EORT);
#line 28 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 28 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
    
    while(1)
    {
    	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor", ECPGt_EOIT, 
	ECPGt_char,(STREET_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(TRAFFIC),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 31 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 31 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;		
	printf("%s \t %s \t %s \t %s \n", STREET_NAME, TRAFFIC, CITY_NAME_2, DISTRICT_NAME_2);
    }
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);
#line 35 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 35 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 36 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 37 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 38 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 39 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 39 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 39 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

    printf("\n");
    return 0;
}

int UpdateStreetTable() {
    /* exec sql begin declare section */
         
         
         
    
#line 46 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char CITY_NAME_key_2 [ 256 ] ;
 
#line 47 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char DISTRICT_NAME_key_2 [ 256 ] ;
 
#line 48 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char STREET_NAME_key_2 [ 256 ] ;
/* exec sql end declare section */
#line 49 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"


    printf("Введите названия города, района и улицы, данные о которой вы хотите изменить: \n ");
    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_key_2);

    printf("Введите название района > ");
    readStringFromConsole(DISTRICT_NAME_key_2);

    printf("Введите название улицы > ");
    readStringFromConsole(STREET_NAME_key_2);
    
    printf("Введите новое название улицы > ");
    readStringFromConsole(STREET_NAME);
	
    printf("Введите новый тип движения > ");
    readStringFromConsole(TRAFFIC);

    printf("Введите новое название города > ");
    readStringFromConsole(CITY_NAME_2);

    printf("Введите новое название района > ");
    readStringFromConsole(DISTRICT_NAME_2);

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update STREET set STREET_NAME = $1  , TRAFFIC = $2  , CITY_NAME_2 = $3  , DISTRICT_NAME_2 = $4  where STREET_NAME = $5  and CITY_NAME_2 = $6  and DISTRICT_NAME_2 = $7 ", 
	ECPGt_char,(STREET_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(TRAFFIC),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(STREET_NAME_key_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_key_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_key_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 73 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 73 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 73 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 73 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 74 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 75 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 76 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
	
    { ECPGtrans(__LINE__, NULL, "commit");
#line 77 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 77 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 77 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

    printf("\n");
    return 0;
}

int InsertStreetTable() {
    printf("Введите название улицы > ");
    readStringFromConsole(STREET_NAME);
	
    printf("Введите тип движения > ");
    readStringFromConsole(TRAFFIC);

    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_2);

    printf("Введите название района > ");
    readStringFromConsole(DISTRICT_NAME_2);

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into STREET ( STREET_NAME , TRAFFIC , CITY_NAME_2 , DISTRICT_NAME_2 ) values ( $1  , $2  , $3  , $4  )", 
	ECPGt_char,(STREET_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(TRAFFIC),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 95 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 95 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 95 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 95 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 96 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 97 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 98 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 99 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 99 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 99 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

    printf("\n");
    return 0;
}

int DeleteStreetTable() {
    /* exec sql begin declare section */
         
         
         
    
#line 106 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char CITY_NAME_key_2 [ 256 ] ;
 
#line 107 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char DISTRICT_NAME_key_2 [ 256 ] ;
 
#line 108 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char STREET_NAME_key_2 [ 256 ] ;
/* exec sql end declare section */
#line 109 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"


    printf("Введите названия города, района и улицы, которую вы хотите удалить: \n ");
    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_key_2);

    printf("Введите название района > ");
    readStringFromConsole(DISTRICT_NAME_key_2);

    printf("Введите название улицы > ");
    readStringFromConsole(STREET_NAME_key_2);

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from STREET where STREET_NAME = $1  and CITY_NAME_2 = $2  and DISTRICT_NAME_2 = $3 ", 
	ECPGt_char,(STREET_NAME_key_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_key_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_key_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 121 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 121 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 121 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 121 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"


	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 123 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 124 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 125 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 126 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 126 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 126 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

    printf("\n");
    return 0;
}

int SelectStreetTable() {
    /* exec sql begin declare section */
         
    
#line 133 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
 char CITY_NAME_key_2 [ 256 ] ;
/* exec sql end declare section */
#line 134 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"


    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_key_2);

    printf("Таблица улиц \n");
	printf("%s \t %s \t %s \t %s \n", "Название улицы", "Движение", "Название города", "Название района");
	printf("______________________________________________________________________________________________________________\n");

    ECPGset_var( 0, ( CITY_NAME_key_2 ), __LINE__);\
 /* declare MyCursor2 cursor for select coalesce ( STREET_NAME , '' ) , coalesce ( TRAFFIC , '' ) , coalesce ( CITY_NAME_2 , '' ) , coalesce ( DISTRICT_NAME_2 , '' ) from STREET where CITY_NAME_2 = $1  order by STREET_NAME */
#line 144 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor2 cursor for select coalesce ( STREET_NAME , '' ) , coalesce ( TRAFFIC , '' ) , coalesce ( CITY_NAME_2 , '' ) , coalesce ( DISTRICT_NAME_2 , '' ) from STREET where CITY_NAME_2 = $1  order by STREET_NAME", 
	ECPGt_char,(CITY_NAME_key_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 145 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 145 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 145 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"
    
    while(1)
    {
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor2", ECPGt_EOIT, 
	ECPGt_char,(STREET_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(TRAFFIC),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_2),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 148 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 148 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 148 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 148 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;		
	printf("%s \t %s \t %s \t %s \n", STREET_NAME, TRAFFIC, CITY_NAME_2, DISTRICT_NAME_2);
    }
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor2", ECPGt_EOIT, ECPGt_EORT);
#line 152 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 152 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 152 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	
        /* exec sql whenever sqlerror  call error1 ( ) ; */
#line 154 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 155 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 156 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 157 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 157 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 157 "D:\\RGR2_DB\\RGR2_DB\\StreetActions.txt"

    printf("\n");
    return 0;
}

