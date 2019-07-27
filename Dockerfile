FROM fedora:25
RUN dnf install -y libX11-devel libXext-devel libSM-devel libXinerama-devel libXrandr-devel lua-devel readline-devel make gcc git gettext
RUN dnf install -y libXft-devel
ADD . /src
WORKDIR /src
RUN make clean && make PREFIX=/opt/notion
RUN make install PREFIX=/opt/notion
WORKDIR /opt
RUN tar czf /notion.tgz notion
