#include "network.h"

using asio::ip::tcp;

class ClientSession : public std::enable_shared_from_this<ClientSession> {
private:
    tcp::socket socket_;
    tcp::resolver resolver_;
    bool connected_ = true;
public:
    ClientSession(asio::io_context& io, std::string ip, std::string port) 
    : socket_(io), resolver_(io) {
        auto endpoints = resolver_.resolve(ip, port);
        asio::connect(socket_, endpoints);
        for (;;) {
            char buf[1024];
            std::error_code error;
            size_t len = socket_.read_some(asio::buffer(buf), error);

            if (error == asio::error::eof)
                break; 
            else if (error)
                throw std::system_error(error);

            std::cout.write(buf, len);
            printf("message? : %s", buf);
        }
    }
    
    tcp::socket& socket() { return socket_; }

    void start() {
        async_read();
    }

    void send(const std::string& message) {
        asio::async_write(socket_, asio::buffer(message),
            [self = shared_from_this()](std::error_code ec, size_t) {
                if (ec) self->connected_ = false;
            });
    }

    bool is_connected() const { return connected_; }


    private:
    void async_read() {
        auto self = shared_from_this();
    }
};

class Server {
private:
    asio::io_context& io_;
    tcp::acceptor acceptor_;
    std::vector<std::shared_ptr<ClientSession>> clients_;
    std::atomic<int> next_id_{1};
public:
    Server(asio::io_context& io, int port) 
    : io_(io), acceptor_(io, tcp::endpoint(tcp::v4(), port)) {
        printf("Server running on port %s...\n", port);
    }

    void handle_connection(tcp::socket socket) {

    }


    void send_message(const std::string& message, int userid) {
        for (auto& client : clients_) {
            if(client->is_connected()) {
                client->send(message);
            }
        }        
    }
};

int create_server() {
    int port = 8080;
    try {
        asio::io_context io;
        Server *server = new Server(io, port);
        return 0;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}


