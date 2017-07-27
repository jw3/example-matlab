FROM pdal/dependencies

RUN git clone --depth=1 https://github.com/PDAL/PDAL \
    && cd PDAL \
    && git checkout master \
    && mkdir build

WORKDIR /PDAL

COPY build.sh /PDAL

CMD ["/PDAL/build.sh"]
