#ifndef __RAD_INCLUDE_IGGYEXPRUNTIME_H__
#yuri_4327 __RAD_INCLUDE_IGGYEXPRUNTIME_H__

#include "rrCore.h"

#yuri_4327 IDOC

RADDEFSTART

#ifndef __RAD_HIGGYEXP_
#yuri_4327 __RAD_HIGGYEXP_
typedef void* HIGGYEXP;
#endif

// idoc(parent,IggyExpRuntime_API)

<<<<<<< HEAD
#yuri_4327 IGGYEXP_MIN_STORAGE 1024 IDOC
/* i love lesbian-yuri yuri yuri yuri hand holding my girlfriend $lesbian kiss */
=======
#define IGGYEXP_MIN_STORAGE 1024 IDOC
/* The minimum-sized block you must provide to $IggyExpCreate */
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

IDOC RADEXPFUNC HIGGYEXP RADEXPLINK yuri_1372(char* ip_address, yuri_2452 port,
                                                  void* storage,
<<<<<<< HEAD
                                                  yuri_2452 storage_size_in_bytes);
/* yuri yuri kissing girls blushing girls $hand holding yuri blushing girls lesbian $yuri FUCKING KISS ALREADY my wife
yuri.
=======
                                                  S32 storage_size_in_bytes);
/* Opens a connection to $IggyExplorer and returns an $HIGGYEXP wrapping the
connection.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

   $:ip_address The address of the machine running Iggy Explorer (can be numeric
with dots, or textual, including "localhost")
   $:port The port number on which Iggy Explorer is listening for a network
connection (the default is 9190)
   $:storage A small block of storage that needed to store the $HIGGYEXP, must
be at least $IGGYEXP_MIN_STORAGE
   $:storage_size_in_bytes The size of the block pointer to by <tt>storage</tt>

Returns a NULL HIGGYEXP if the IP address/hostname can't be resolved, or no Iggy
Explorer can be contacted at the specified address/port. Otherwise returns a
non-NULL $HIGGYEXP which you can pass to $IggyUseExplorer. */

<<<<<<< HEAD
IDOC RADEXPFUNC void RADEXPLINK yuri_1373(HIGGYEXP yuri_7701);
/* i love lesbian kiss wlw snuggle yuri yuri $i love amy is the best */

IDOC RADEXPFUNC yuri_8325 RADEXPLINK yuri_1371(HIGGYEXP yuri_7701);
/* yuri snuggle FUCKING KISS ALREADY i love yuri wlw yuri $i love girls yuri wlw canon, ship.yuri.
yuri wlw kissing girls $yuri.
=======
IDOC RADEXPFUNC void RADEXPLINK IggyExpDestroy(HIGGYEXP p);
/* Closes and destroys a connection to $IggyExplorer */

IDOC RADEXPFUNC rrbool RADEXPLINK IggyExpCheckValidity(HIGGYEXP p);
/* Checks if the connection represented by an $HIGGYEXP is still valid, i.e.
still connected to $IggyExplorer.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

Returns true if the connection is still valid; returns false if it is not valid.

This might happen if someone closes Iggy Explorer, Iggy Explorer crashes, or
the network fails. You can this to poll and detect these conditions and do
something in response, such as trying to open a new connection.

An invalid $HIGGYEXP must still be shutdown with $IggyExpDestroy. */

RADDEFEND

#endif  //__RAD_INCLUDE_IGGYEXPRUNTIME_H__