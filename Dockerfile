FROM ubuntu:18.04
RUN apt-get update

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Moscow
ENV LANG=C.UTF-8

RUN apt-get update && apt-get install -y tzdata locales

RUN ln -fs /usr/share/zoneinfo/$TZ /etc/localtime && dpkg-reconfigure -f noninteractive tzdata
RUN sed -i -e "s/# $LANG UTF-8/$LANG UTF-8/" /etc/locale.gen && locale-gen


RUN apt-get install -y build-essential
RUN apt-get install -y qt5-default
RUN apt-get install -y clang
RUN apt-get install -y qt5-qmake
RUN apt-get install -y qtbase5-dev

WORKDIR /usr/my_app
COPY . .

#VOLUME /my_app


RUN qmake echoServer.pro
RUN make
CMD ["./echoserver"]


