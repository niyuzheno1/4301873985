#include <click/config.h>
#include "SimplePullElement.hh"
#include <click/confparse.hh>
#include <click/error.hh>
#include <click/straccum.hh>

CLICK_DECLS

SimplePullElement::SimplePullElement() {}
SimplePullElement::~SimplePullElement() {}
int
SimplePullElement::configure(Vector<String> &conf, ErrorHandler* errh)
{
	if (cp_va_kparse(conf, this, errh, "MAXPACKETSIZE", cpkM, cpInteger, &maxSize, cpEnd) < 0) return -1;
	if (maxSize <= 0) return errh->error("maxsize should be larger than 0");
	return 0;
}

void SimplePullElement::push(int, Packet *p) {
	const unsigned char *data = p->data();
	
	int bytes = p->length();
	StringAccum sa(bytes+10);
	char * buf = sa.data();
	for (int i = 0; i < bytes; i++, data++,buf++) {
		sa << *data;
	}
	click_chatter("Got a packet: %s", sa.c_str());
	p->kill();
}

CLICK_ENDDECLS
EXPORT_ELEMENT(SimplePullElement)
