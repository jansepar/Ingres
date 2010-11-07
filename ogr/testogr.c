#include "ogr_api.h"

int main()
{
 OGRErr eErr;
 OGRGeometryH hGeom = NULL;
 char *kml = NULL;
 //unsigned char *wkb_buffer = "\x01\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x14@\x00\x00\x00\x00\x00\x007@";
 unsigned char *wkb_buffer = "\001\001\000\000\000\000\000\000\000\000\000$@\000\000\000\000\000\000$@";

 eErr = OGR_G_CreateFromWkb( wkb_buffer, NULL, &hGeom, -1 );
 if( eErr == OGRERR_NONE )
 {
   kml = OGR_G_ExportToKML( hGeom, "???I do not know what this is" );
   OGR_G_DestroyGeometry( hGeom );
   printf( "kml = %s\n", kml );
   //CPLFree( kml );
    }
     else if( eErr == OGRERR_NOT_ENOUGH_DATA )
   {
   printf("error1");
   }
   else if( eErr == OGRERR_UNSUPPORTED_GEOMETRY_TYPE )
   {
   printf("error2");
   }
   else if( eErr == OGRERR_CORRUPT_DATA )
   {
   printf("error3");
   };
   
  }
