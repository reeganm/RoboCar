#include "ethernet_coms.h"

#include "mail_box.h"

// https://os.mbed.com/teams/ST/code/mbed-os-tcp-server-example/file/e72bc303ea90/main.cpp/

Mail<mail_t, 16> mail_box;

#define HTTP_STATUS_LINE "HTTP/1.0 200 OK"
#define HTTP_HEADER_FIELDS "Content-Type: text/html; charset=utf-8"
#define HTTP_MESSAGE_BODY ""                                     \
"<html>" "\r\n"                                                  \
"  <body style=\"display:flex;text-align:center\">" "\r\n"       \
"    <div style=\"margin:auto\">" "\r\n"                         \
"      <h1>Hello World</h1>" "\r\n"                              \
"      <p>It works !</p>" "\r\n"                                 \
"    </div>" "\r\n"                                              \
"  </body>" "\r\n"                                               \
"</html>"

#define HTTP_RESPONSE HTTP_STATUS_LINE "\r\n"   \
                      HTTP_HEADER_FIELDS "\r\n" \
                      "\r\n"                    \
                      HTTP_MESSAGE_BODY "\r\n"

char buffer[256];

void ethernet_thread(void)
{

  printf("Basic HTTP server example\n");

  EthernetInterface eth;
  eth.connect();

  printf("The target IP address is '%s'\n", eth.get_ip_address());

  TCPServer srv;
  TCPSocket clt_sock;
  SocketAddress clt_addr;

  /* Open the server on ethernet stack */
  srv.open(&eth);

  /* Bind the HTTP port (TCP 80) to the server */
  srv.bind(eth.get_ip_address(), 80);

  /* Can handle 5 simultaneous connections */
  srv.listen(5);

  while(1)
  {
    srv.accept(&clt_sock, &clt_addr);
    printf("accept %s:%d\n", clt_addr.get_ip_address(), clt_addr.get_port());

    clt_sock.recv(buffer, 256);

    printf("%s\n",buffer);
    clt_sock.send(HTTP_RESPONSE, strlen(HTTP_RESPONSE));

    mail_t *mail = mail_box.alloc();
    mail_box.put(mail);
    wait(0.5f);
  }
}
