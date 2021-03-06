// COPYRIGHT Dassault Systemes 2022
//===================================================================
//
// TRACommandAddin.cpp
// Provide implementation to interface
//    CATIAssyWorkBenchAddin
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  Jun 2022  Creation: Code generated by the CAA wizard  Dell
//===================================================================
#include "TRACommandAddin.h"

// ApplicationFrame Framework 
#include <CATCreateWorkshop.h>    

// Creates the CAAAfrGeoOperationAdnHeader command header class
#include "CATCommandHeader.h"
MacDeclareHeader(TRACommandAddinHeader); 
 
CATImplementClass(TRACommandAddin,
                  DataExtension,
                  CATBaseUnknown,
                  TRAECommandAddin );
 

//-----------------------------------------------------------------------------
// TRACommandAddin : constructor
//-----------------------------------------------------------------------------
TRACommandAddin::TRACommandAddin():
    CATBaseUnknown()
{
}

//-----------------------------------------------------------------------------
// TRACommandAddin : destructor
//-----------------------------------------------------------------------------
TRACommandAddin::~TRACommandAddin()
{
}
 
// Link the implementation to its interface
// ---------------------------------------



//TIE or TIEchain definitions
#include "TIE_CATIAssyWorkBenchAddin.h"
TIE_CATIAssyWorkBenchAddin( TRACommandAddin);


//Methods implementation

void TRACommandAddin::CreateCommands()
{
   //---------------------------------------------------------------------------
   // Instantiation of the header class created by the macro MacDeclareHeader -
   // commands are always available and are represented by a push button
   //---------------------------------------------------------------------------

   new TRACommandAddinHeader("CreateLineHdr"    ,"TRAStCommand","TRAStateCommand",(void *)NULL);
   
}

CATCmdContainer * TRACommandAddin::CreateToolbars()
{
   // --------------------------
   // CAAAfrOperationTlb Toolbar
   // --------------------------- 
  NewAccess (CATCmdContainer ,pToolbar,Toolbar);

	NewAccess (CATCmdStarter  ,pButton,Button);

	SetAccessCommand (pButton,"CreateLineHdr");


	SetAccessChild (pToolbar,pButton);

	AddToolbarView (pToolbar,1,Left);

	return pToolbar;
}