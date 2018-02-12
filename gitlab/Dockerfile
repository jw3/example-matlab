FROM pdal/dependencies

COPY *.deb /tmp

RUN dpkg -i /tmp/*.deb \
 && rm /tmp/* \
 && pdal --version
