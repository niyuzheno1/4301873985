#ifndef CLICK_SIMPLEPULLELEMENT_HH
#define CLICK_SIMPLEPULLELEMENT_HH
#include <click/element.hh>
CLICK_DECLS

class SimplePullElement : public Element { public:
  SimplePullElement();
  ~SimplePullElement();

  const char *class_name() const { return "SimplePullElement"; }
  const char *port_count() const { return PORTS_1_1; }
  const char *processing() const { return PUSH; }
  int configure(Vector<String> &, ErrorHandler *);
  void push(int port, Packet *p);

 private:
	 unsigned int maxSize;
};

CLICK_ENDDECLS
#endif