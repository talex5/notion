#include <X11/Xatom.h>

#include "global.h"
#include "qubes.h"
#include "property.h"


/*{{{ Atoms */

static Atom atom_qubes_vmname=0;
static Atom atom_qubes_label_color=0;

#define N_QUBES 2

/*}}}*/


/*{{{ Initialisation */


void qubes_init()
{
    atom_qubes_vmname=XInternAtom(ioncore_g.dpy, "_QUBES_VMNAME", False);
    atom_qubes_label_color=XInternAtom(ioncore_g.dpy, "_QUBES_LABEL_COLOR", False);
}


/*}}}*/


/*{{{ _QUBES_VMNAME */


char **qubes_vmname(WClientWin *cwin)
{
    return xwindow_get_text_property(cwin->win, atom_qubes_vmname, NULL);
}

/*}}}*/


/*{{{ _QUBES_LABEL_COLOR */

Atom qubes_label_color(WClientWin *cwin)
{
    int c = 0;
    if(xwindow_get_integer_property(cwin->win, atom_qubes_label_color, &c)){
        return c;
    }
    return 0;
}

/*}}}*/
