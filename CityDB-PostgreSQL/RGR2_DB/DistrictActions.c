/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
/* exec sql begin declare section */
     
     
     
     
     
     
     
     

#line 2 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
 char DISTRICT_NAME_key_1 [ 256 ] ;
 
#line 3 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
 char CITY_NAME_key_1 [ 256 ] ;
 
#line 4 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
 char DISTRICT_NAME [ 256 ] ;
 
#line 5 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
 char OKRUG [ 256 ] ;
 
#line 6 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
 char AREA [ 256 ] ;
 
#line 7 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
 char DISTRICT_POPULATION [ 256 ] ;
 
#line 8 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
 char CITY_NAME_1 [ 256 ] ;
 
#line 9 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
 char OKRUG_key_1 [ 256 ] ;
/* exec sql end declare section */
#line 10 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"


/* exec sql whenever sqlerror  sqlprint ; */
#line 12 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"


int ReadDistrictTable();
int UpdateDistrictTable();
int InsertDistrictTable();
int DeleteDistrictTable();
int SelectDistrictTable();

void error1();
void error2();
void error3();

void readStringFromConsole(char str[256]);

int ReadDistrictTable() {
    printf("Таблица районов \n");
	printf("%s \t %s \t %s \t %s \t %s \n", "Название района", "Округ", "Площадь", "Население", "Название города");
	printf("______________________________________________________________________________________________________________\n");
    /* declare MyCursor cursor for select coalesce ( DISTRICT_NAME , '' ) , coalesce ( OKRUG , '' ) , coalesce ( AREA , '' ) , coalesce ( DISTRICT_POPULATION , '' ) , coalesce ( CITY_NAME_1 , '' ) from DISTRICT order by DISTRICT_NAME */
#line 31 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for select coalesce ( DISTRICT_NAME , '' ) , coalesce ( OKRUG , '' ) , coalesce ( AREA , '' ) , coalesce ( DISTRICT_POPULATION , '' ) , coalesce ( CITY_NAME_1 , '' ) from DISTRICT order by DISTRICT_NAME", ECPGt_EOIT, ECPGt_EORT);
#line 32 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 32 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
    
    while(1)
    {
    	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor", ECPGt_EOIT, 
	ECPGt_char,(DISTRICT_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(OKRUG),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(AREA),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 35 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 35 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;		
	printf("%s \t %s \t %s \t %s \t %s \n", DISTRICT_NAME, OKRUG, AREA, DISTRICT_POPULATION, CITY_NAME_1);
    }
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);
#line 39 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 39 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 40 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 41 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 42 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 43 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 43 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 43 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    printf("\n");
    return 0;
}

int UpdateDistrictTable() {
    printf("Введите названия города и района, данные о котором вы хотите изменить: \n ");
    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_key_1);

    printf("Введите название района > ");
    readStringFromConsole(DISTRICT_NAME_key_1);
    
    printf("Введите новое название района > ");
    readStringFromConsole(DISTRICT_NAME);
	
    printf("Введите новое название округа (если он есть) > ");
    readStringFromConsole(OKRUG);

    printf("Введите новое значение площади > ");
    readStringFromConsole(AREA);

    printf("Введите новую численность населения > ");
    readStringFromConsole(DISTRICT_POPULATION);
    
    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_1);

    if(OKRUG[0] == '\0') {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update DISTRICT set DISTRICT_NAME = $1  , AREA = $2  , DISTRICT_POPULATION = $3  , CITY_NAME_1 = $4  where DISTRICT_NAME = $5  and CITY_NAME_1 = $6 ", 
	ECPGt_char,(DISTRICT_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(AREA),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_key_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_key_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 72 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 72 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 72 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 72 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    } else {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update DISTRICT set DISTRICT_NAME = $1  , OKRUG = $2  , AREA = $3  , DISTRICT_POPULATION = $4  , CITY_NAME_1 = $5  where DISTRICT_NAME = $6  and CITY_NAME_1 = $7 ", 
	ECPGt_char,(DISTRICT_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(OKRUG),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(AREA),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_key_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_key_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 74 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 74 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 74 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 74 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    }
	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 76 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 77 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 78 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
	
    { ECPGtrans(__LINE__, NULL, "commit");
#line 79 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 79 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 79 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    printf("\n");
    return 0;
}

int InsertDistrictTable() {
    printf("Введите название района > ");
    readStringFromConsole(DISTRICT_NAME);
	
    printf("Введите название округа > ");
    readStringFromConsole(OKRUG);

    printf("Введите значение площади > ");
    readStringFromConsole(AREA);

    printf("Введите численность населения > ");
    readStringFromConsole(DISTRICT_POPULATION);
    
    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_1);

    if(OKRUG[0] == '\0') {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into DISTRICT ( DISTRICT_NAME , AREA , DISTRICT_POPULATION , CITY_NAME_1 ) values ( $1  , $2  , $3  , $4  )", 
	ECPGt_char,(DISTRICT_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(AREA),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 101 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 101 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 101 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 101 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    } else {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into DISTRICT ( DISTRICT_NAME , OKRUG , AREA , DISTRICT_POPULATION , CITY_NAME_1 ) values ( $1  , $2  , $3  , $4  , $5  )", 
	ECPGt_char,(DISTRICT_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(OKRUG),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(AREA),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 103 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 103 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 103 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 103 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    }
	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 105 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 106 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 107 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 108 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 108 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 108 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    printf("\n");
    return 0;
}

int DeleteDistrictTable() {
    printf("Введите названия города и района, который вы хотите удалить: \n ");
    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_key_1);

    printf("Введите название района > ");
    readStringFromConsole(DISTRICT_NAME_key_1);

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from DISTRICT where DISTRICT_NAME = $1  and CITY_NAME_1 = $2 ", 
	ECPGt_char,(DISTRICT_NAME_key_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_key_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 121 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 121 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 121 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 121 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"


	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 123 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 124 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 125 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 126 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 126 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 126 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    printf("\n");
    return 0;
}

int SelectDistrictTable() {
    printf("Введите название округа, в котором хотите найти районы > ");
    readStringFromConsole(OKRUG_key_1);

    printf("Таблица районов \n");
	printf("%s \t %s \t %s \t %s \t %s \n", "Название района", "Округ", "Площадь", "Население", "Название города");
	printf("______________________________________________________________________________________________________________\n");

    /* declare MyCursor2 cursor for select coalesce ( DISTRICT_NAME , '' ) , coalesce ( OKRUG , '' ) , coalesce ( AREA , '' ) , coalesce ( DISTRICT_POPULATION , '' ) , coalesce ( CITY_NAME_1 , '' ) from DISTRICT where OKRUG = $1  order by DISTRICT_NAME */
#line 140 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor2 cursor for select coalesce ( DISTRICT_NAME , '' ) , coalesce ( OKRUG , '' ) , coalesce ( AREA , '' ) , coalesce ( DISTRICT_POPULATION , '' ) , coalesce ( CITY_NAME_1 , '' ) from DISTRICT where OKRUG = $1  order by DISTRICT_NAME", 
	ECPGt_char,(OKRUG_key_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 141 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 141 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 141 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"
    
    while(1)
    {
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor2", ECPGt_EOIT, 
	ECPGt_char,(DISTRICT_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(OKRUG),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(AREA),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_POPULATION),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_1),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 144 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 144 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 144 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 144 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;		
	printf("%s \t %s \t %s \t %s \t %s \n", DISTRICT_NAME, OKRUG, AREA, DISTRICT_POPULATION, CITY_NAME_1);
    }
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor2", ECPGt_EOIT, ECPGt_EORT);
#line 148 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 148 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 148 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	
        /* exec sql whenever sqlerror  call error1 ( ) ; */
#line 150 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 151 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 152 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 153 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 153 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 153 "D:\\RGR2_DB\\RGR2_DB\\DistrictActions.txt"

    printf("\n");
    return 0;
}

