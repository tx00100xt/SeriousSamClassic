#ifndef __DOS4G__
#error must compile for DOS4G
#endif

#ifndef __TIMER_H
#define __TIMER_H

void tmInit();
void tmClose();
unsigned long tmGetTimer();

#endif
