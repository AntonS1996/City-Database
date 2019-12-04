/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
/* exec sql begin declare section */
     
     
     
     
     
     

#line 2 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char NUM [ 256 ] ;
 
#line 3 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char POSTCODE [ 256 ] ;
 
#line 4 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char BUILDING_TYPE [ 256 ] ;
 
#line 5 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char CITY_NAME_3 [ 256 ] ;
 
#line 6 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char DISTRICT_NAME_3 [ 256 ] ;
 
#line 7 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char STREET_NAME_3 [ 256 ] ;
/* exec sql end declare section */
#line 8 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"


/* exec sql whenever sqlerror  sqlprint ; */
#line 10 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"


int ReadBuildingTable();
int UpdateBuildingTable();
int InsertBuildingTable();
int DeleteBuildingTable();
int SelectBuildingTable();

void error1();
void error2();
void error3();

void readStringFromConsole(char str[256]);

int ReadBuildingTable() {
    printf("Таблица зданий \n");
	printf("%s \t %s \t %s \t %s \t %s \t %s \n", "Номер", "Почтовый индекс", "Тип здания", "Название города", "Название района", "Название улицы");
	printf("______________________________________________________________________________________________________________\n");
    /* declare MyCursor cursor for select coalesce ( NUM , '' ) , coalesce ( POSTCODE , '' ) , coalesce ( BUILDING_TYPE , '' ) , coalesce ( CITY_NAME_3 , '' ) , coalesce ( DISTRICT_NAME_3 , '' ) , coalesce ( STREET_NAME_3 , '' ) from BUILDING order by STREET_NAME_3 */
#line 29 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for select coalesce ( NUM , '' ) , coalesce ( POSTCODE , '' ) , coalesce ( BUILDING_TYPE , '' ) , coalesce ( CITY_NAME_3 , '' ) , coalesce ( DISTRICT_NAME_3 , '' ) , coalesce ( STREET_NAME_3 , '' ) from BUILDING order by STREET_NAME_3", ECPGt_EOIT, ECPGt_EORT);
#line 30 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 30 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
    
    while(1)
    {
    	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor", ECPGt_EOIT, 
	ECPGt_char,(NUM),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(POSTCODE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(BUILDING_TYPE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(STREET_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 33 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 33 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;		
	printf("%s \t %s \t %s \t %s \t %s \t %s \n", NUM, POSTCODE, BUILDING_TYPE, CITY_NAME_3, DISTRICT_NAME_3, STREET_NAME_3);
    }
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);
#line 37 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) sqlprint();}
#line 37 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 38 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 39 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 40 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 41 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 41 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 41 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

    printf("\n");
    return 0;
}

int UpdateBuildingTable() {
    /* exec sql begin declare section */
         
         
         
         
         
    
#line 48 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char CITY_NAME_key_3 [ 256 ] ;
 
#line 49 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char DISTRICT_NAME_key_3 [ 256 ] ;
 
#line 50 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char STREET_NAME_key_3 [ 256 ] ;
 
#line 51 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char NUM_key_3 [ 256 ] ;
 
#line 52 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char POSTCODE_key_3 [ 256 ] ;
/* exec sql end declare section */
#line 53 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"


    printf("Введите данные о здании, информацию о котором вы хотите изменить: \n ");
    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_key_3);

    printf("Введите название района > ");
    readStringFromConsole(DISTRICT_NAME_key_3);

    printf("Введите название улицы > ");
    readStringFromConsole(STREET_NAME_key_3);

    printf("Введите номер здания > ");
    readStringFromConsole(NUM_key_3);

    printf("Введите почтовый индекс здания > ");
    readStringFromConsole(POSTCODE_key_3);
    
    printf("Введите новый номер здания > ");
    readStringFromConsole(NUM);
	
    printf("Введите новый почтовый индекс > ");
    readStringFromConsole(POSTCODE);

    printf("Введите новый тип здания > ");
    readStringFromConsole(BUILDING_TYPE);

    printf("Введите новое название города > ");
    readStringFromConsole(CITY_NAME_3);

    printf("Введите новое название района > ");
    readStringFromConsole(DISTRICT_NAME_3);

    printf("Введите новое название улицы > ");
    readStringFromConsole(STREET_NAME_3);

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update BUILDING set NUM = $1  , POSTCODE = $2  , BUILDING_TYPE = $3  , CITY_NAME_3 = $4  , DISTRICT_NAME_3 = $5  , STREET_NAME_3 = $6  where NUM = $7  and POSTCODE = $8  and CITY_NAME_3 = $9  and DISTRICT_NAME_3 = $10  and STREET_NAME_3 = $11 ", 
	ECPGt_char,(NUM),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(POSTCODE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(BUILDING_TYPE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(STREET_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(NUM_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(POSTCODE_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(STREET_NAME_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 89 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 89 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 89 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 89 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 90 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 91 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 92 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
	
    { ECPGtrans(__LINE__, NULL, "commit");
#line 93 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 93 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 93 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

    printf("\n");
    return 0;
}

int InsertBuildingTable() {
    printf("Введите номер здания > ");
    readStringFromConsole(NUM);
	
    printf("Введите почтовый индекс > ");
    readStringFromConsole(POSTCODE);

    printf("Введите тип здания > ");
    readStringFromConsole(BUILDING_TYPE);

    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_3);

    printf("Введите название района > ");
    readStringFromConsole(DISTRICT_NAME_3);

    printf("Введите название улицы > ");
    readStringFromConsole(STREET_NAME_3);

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into BUILDING ( NUM , POSTCODE , BUILDING_TYPE , CITY_NAME_3 , DISTRICT_NAME_3 , STREET_NAME_3 ) values ( $1  , $2  , $3  , $4  , $5  , $6  )", 
	ECPGt_char,(NUM),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(POSTCODE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(BUILDING_TYPE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(STREET_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 117 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 117 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 117 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 117 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 118 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 119 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 120 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 121 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 121 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 121 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

    printf("\n");
    return 0;
}

int DeleteBuildingTable() {
    /* exec sql begin declare section */
         
         
         
         
         
    
#line 128 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char CITY_NAME_key_3 [ 256 ] ;
 
#line 129 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char DISTRICT_NAME_key_3 [ 256 ] ;
 
#line 130 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char STREET_NAME_key_3 [ 256 ] ;
 
#line 131 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char NUM_key_3 [ 256 ] ;
 
#line 132 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char POSTCODE_key_3 [ 256 ] ;
/* exec sql end declare section */
#line 133 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"


    printf("Введите данные о здании, которое вы хотите удалить: \n ");
    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_key_3);

    printf("Введите название района > ");
    readStringFromConsole(DISTRICT_NAME_key_3);

    printf("Введите название улицы > ");
    readStringFromConsole(STREET_NAME_key_3);

    printf("Введите номер здания > ");
    readStringFromConsole(NUM_key_3);

    printf("Введите почтовый индекс здания > ");
    readStringFromConsole(POSTCODE_key_3);

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from BUILDING where NUM = $1  and POSTCODE = $2  and CITY_NAME_3 = $3  and DISTRICT_NAME_3 = $4  and STREET_NAME_3 = $5 ", 
	ECPGt_char,(NUM_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(POSTCODE_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(STREET_NAME_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 151 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 151 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 151 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 151 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"


	/* exec sql whenever sqlerror  call error1 ( ) ; */
#line 153 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 154 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 155 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 156 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 156 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 156 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

    printf("\n");
    return 0;
}

int SelectBuildingTable() {
    /* exec sql begin declare section */
         
         
    
#line 163 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char CITY_NAME_key_3 [ 256 ] ;
 
#line 164 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
 char STREET_NAME_key_3 [ 256 ] ;
/* exec sql end declare section */
#line 165 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"


    printf("Введите название города > ");
    readStringFromConsole(CITY_NAME_key_3);

    printf("Введите название улицы > ");
    readStringFromConsole(STREET_NAME_key_3);

    printf("Таблица зданий \n");
	printf("%s \t %s \t %s \t %s \t %s \t %s \n", "Номер", "Почтовый индекс", "Тип здания", "Название города", "Название района", "Название улицы");
	printf("______________________________________________________________________________________________________________\n");

    ECPGset_var( 0, ( STREET_NAME_key_3 ), __LINE__);\
 ECPGset_var( 1, ( CITY_NAME_key_3 ), __LINE__);\
 /* declare MyCursor2 cursor for select coalesce ( NUM , '' ) , coalesce ( POSTCODE , '' ) , coalesce ( BUILDING_TYPE , '' ) , coalesce ( CITY_NAME_3 , '' ) , coalesce ( DISTRICT_NAME_3 , '' ) , coalesce ( STREET_NAME_3 , '' ) from BUILDING where CITY_NAME_3 = $1  and STREET_NAME_3 = $2  order by STREET_NAME_3 */
#line 178 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor2 cursor for select coalesce ( NUM , '' ) , coalesce ( POSTCODE , '' ) , coalesce ( BUILDING_TYPE , '' ) , coalesce ( CITY_NAME_3 , '' ) , coalesce ( DISTRICT_NAME_3 , '' ) , coalesce ( STREET_NAME_3 , '' ) from BUILDING where CITY_NAME_3 = $1  and STREET_NAME_3 = $2  order by STREET_NAME_3", 
	ECPGt_char,(CITY_NAME_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(STREET_NAME_key_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 179 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 179 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 179 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"
    
    while(1)
    {
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor2", ECPGt_EOIT, 
	ECPGt_char,(NUM),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(POSTCODE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(BUILDING_TYPE),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(CITY_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(DISTRICT_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(STREET_NAME_3),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 182 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode == ECPG_NOT_FOUND) error3 ( );
#line 182 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 182 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 182 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	if (sqlca.sqlcode == ECPG_NOT_FOUND || strncmp(sqlca.sqlstate,"00",2)) break;		
	printf("%s \t %s \t %s \t %s \t %s \t %s \n", NUM, POSTCODE, BUILDING_TYPE, CITY_NAME_3, DISTRICT_NAME_3, STREET_NAME_3);
    }
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor2", ECPGt_EOIT, ECPGt_EORT);
#line 186 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 186 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 186 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	
        /* exec sql whenever sqlerror  call error1 ( ) ; */
#line 188 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever sql_warning  call error2 ( ) ; */
#line 189 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

	/* exec sql whenever not found  call error3 ( ) ; */
#line 190 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 191 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlwarn[0] == 'W') error2 ( );
#line 191 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

if (sqlca.sqlcode < 0) error1 ( );}
#line 191 "D:\\RGR2_DB\\RGR2_DB\\BuildingActions.txt"

    printf("\n");
    return 0;
}

