FROM ubuntu
RUN apt-get update
RUN apt-get install sudo

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Moscow
ENV LANG=C.UTF-8

RUN apt-get update && apt-get install -y tzdata locales

RUN ln -fs /usr/share/zoneinfo/$TZ /etc/localtime && dpkg-reconfigure -f noninteractive tzdata
RUN sed -i -e "s/# $LANG UTF-8/$LANG UTF-8/" /etc/locale.gen && locale-gen

RUN sudo apt-get update && sudo apt-get install gcc -y
RUN sudo apt-get update && sudo apt-get install sqlite3 -y

RUN sudo apt-get update && sudo apt-get install qtcreator -y

RUN echo "Y"





