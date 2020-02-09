/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
/* exec sql begin declare section */
     
     
     
     
     

#line 2 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
 char LANDMARK_NAME [ 256 ] ;
 
#line 3 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
 char CREATION_YEAR [ 256 ] ;
 
#line 4 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
 char LANDMARK_TYPE [ 256 ] ;
 
#line 5 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
 char ARCHITECT [ 256 ] ;
 
#line 6 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
 char CITY_NAME_4 [ 256 ] ;
/* exec sql end declare section */
#line 7 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"


/* exec sql whenever sqlerror  sqlprint ; */
#line 9 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"


int ReadLandmarkTable();
int UpdateLandmarkTable();
int InsertLandmarkTable();
int DeleteLandmarkTable();
int SelectLandmarkTable();

void error1();
void error2();
void error3();

void readStringFromConsole(char str[256]);

int ReadLandmarkTable() {
    printf("Таблица достопримечательностей \n");
	printf("%s \t %s \t %s \t %s \t %s \n", "Название", "Год создания", "Тип", "Архитектор", "Название города");
	printf("______________________________________________________________________________________________________________\n");
    /* declare MyCursor cursor for select coalesce ( LANDMARK_NAME , '' ) , coalesce ( CREATION_YEAR , '' ) , coalesce ( LANDMARK_TYPE , '' ) , coalesce ( ARCHITECT , '' ) , coalesce ( CITY_NAME_4 , '' ) from LANDMARK order by CITY_NAME_4 */
#line 28 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for select coalesce ( LANDMARK_NAME , '' ) , coalesce ( CREATION_YEAR , '' ) , coalesce ( LANDMARK_TYPE , '' ) , coalesce ( ARCHITECT , '' ) , coalesce ( CITY_NAME_4 , '' ) from LANDMARK order by CITY_NAME_4", ECPGt_EOIT, ECPGt_EORT);
#line 29 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 29 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
    
    while(1)
    {
    	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor", ECPGt_EOIT, 
	ECPGt_char,(LANDMARK_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CREATION_YEAR),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(LANDMARK_TYPE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ARCHITECT),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_4),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 32 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 32 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;		
	printf("%s \t %s \t %s \t %s \t %s \n", LANDMARK_NAME, CREATION_YEAR, LANDMARK_TYPE, ARCHITECT, CITY_NAME_4);
    }
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);
#line 36 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 36 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 37 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 38 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 39 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 40 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 40 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 40 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    printf("\n");
    return 0;
}

int UpdateLandmarkTable() {
    /* exec sql begin declare section */
         
    
#line 47 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
 char LANDMARK_NAME_key [ 256 ] ;
/* exec sql end declare section */
#line 48 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"


    printf("Введите название достопримечательности, информацию о которой вы хотите изменить: > ");
    readStringFromConsole(LANDMARK_NAME_key);
    
    printf("Введите новое название достопримечательности > ");
    readStringFromConsole(LANDMARK_NAME);
	
    printf("Введите новый год создания (при необходимости) > ");
    readStringFromConsole(CREATION_YEAR);

    printf("Введите новый тип достопримечательности > ");
    readStringFromConsole(LANDMARK_TYPE);

    printf("Введите нового архитектора > ");
    readStringFromConsole(ARCHITECT);

    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_4);

    if(CREATION_YEAR[0] == '\0') {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update LANDMARK set LANDMARK_NAME = $1  , LANDMARK_TYPE = $2  , ARCHITECT = $3  , CITY_NAME_4 = $4  where LANDMARK_NAME = $5 ", 
	ECPGt_char,(LANDMARK_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(LANDMARK_TYPE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ARCHITECT),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_4),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(LANDMARK_NAME_key),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 69 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 69 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 69 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 69 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    } else {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update LANDMARK set LANDMARK_NAME = $1  , CREATION_YEAR = $2  , LANDMARK_TYPE = $3  , ARCHITECT = $4  , CITY_NAME_4 = $5  where LANDMARK_NAME = $6 ", 
	ECPGt_char,(LANDMARK_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CREATION_YEAR),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(LANDMARK_TYPE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ARCHITECT),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_4),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(LANDMARK_NAME_key),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 71 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 71 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 71 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 71 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    }
	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 73 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 74 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 75 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
	
    { ECPGtrans(__LINE__, NULL, "commit");
#line 76 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 76 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 76 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    printf("\n");
    return 0;
}

int InsertLandmarkTable() {
    printf("Введите название достопримечательности > ");
    readStringFromConsole(LANDMARK_NAME);
	
    printf("Введите год создания > ");
    readStringFromConsole(CREATION_YEAR);

    printf("Введите тип достопримечательности > ");
    readStringFromConsole(LANDMARK_TYPE);

    printf("Введите архитектора > ");
    readStringFromConsole(ARCHITECT);

    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_4);

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into LANDMARK ( LANDMARK_NAME , CREATION_YEAR , LANDMARK_TYPE , ARCHITECT , CITY_NAME_4 ) values ( $1  , $2  , $3  , $4  , $5  )", 
	ECPGt_char,(LANDMARK_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CREATION_YEAR),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(LANDMARK_TYPE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ARCHITECT),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_4),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 97 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 97 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 97 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 97 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 98 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 99 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 100 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 101 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 101 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 101 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    printf("\n");
    return 0;
}

int DeleteLandmarkTable() {
    /* exec sql begin declare section */
         
    
#line 108 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
 char LANDMARK_NAME_key [ 256 ] ;
/* exec sql end declare section */
#line 109 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"


    printf("Введите название достопримечательности, которую вы хотите удалить: > ");
    readStringFromConsole(LANDMARK_NAME_key);

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from LANDMARK where LANDMARK_NAME = $1 ", 
	ECPGt_char,(LANDMARK_NAME_key),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 114 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 114 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 114 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 114 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"


	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 116 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 117 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 118 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 119 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 119 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 119 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    printf("\n");
    return 0;
}

int SelectLandmarkTable() {
    /* exec sql begin declare section */
         
    
#line 126 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"
 char LANDMARK_NAME_key [ 256 ] ;
/* exec sql end declare section */
#line 127 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"


    printf("Введите название достопримечательности > ");
    readStringFromConsole(LANDMARK_NAME_key);

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select LANDMARK_NAME , CREATION_YEAR , LANDMARK_TYPE , ARCHITECT , CITY_NAME_4 from LANDMARK where LANDMARK_NAME = $1 ", 
	ECPGt_char,(LANDMARK_NAME_key),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_char,(LANDMARK_NAME),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CREATION_YEAR),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(LANDMARK_TYPE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ARCHITECT),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_4),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 132 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 132 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 132 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 132 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    printf(" Название достопримечательности: %s\n Год создания: %s\n Тип: %s\n Архитектор: %s\n Название города: %s\n", LANDMARK_NAME, CREATION_YEAR, LANDMARK_TYPE, ARCHITECT, CITY_NAME_4);
	
    	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 135 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 136 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    	/* exec sql whenever not found  call error3 ( ) ; */
#line 137 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 138 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 138 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 138 "D:\\RGR2_DB\\RGR2_DB\\LandmarkActions.txt"

    printf("\n");
    return 0;
}

