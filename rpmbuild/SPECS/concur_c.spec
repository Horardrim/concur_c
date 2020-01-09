%define debug_package %{nil}

Name:    concur-c
Version: 1.0.0
Release: 1%{?dist}
Summary: This package includes the implementation of multi-thread concurrency
Group:   Applications/Internet
License: GPL
BuildRoot: %{_tmppath}/%{name}-%{version}-root
Source0: concur-c-%{version}.tar.gz

%description
There is a shared lib in the rpm which have a basic feature of multi-thread concurrency

%prep
%setup

%build
make

%install
mkdir -p $RPM_BUILD_ROOT/usr/libs/
mkdir -p $RPM_BUILD_ROOT/usr/include/
# install -D %_topdir/BUILD/matrix-c-%{version}/matrix_def.h $RPM_BUILD_ROOT/usr/include/matrix/matrix_def.h
# install -D %_topdir/BUILD/output/libmatrix-c.so $RPM_BUILD_ROOT/usr/lib/libmatrix-c.so
# install -D %_topdir/BUILD/output/libmatrix-c.so.%{version} $RPM_BUILD_ROOT/usr/lib/libmatrix-c.so.%{version}

%clean
rm -rf $RPM_BUILD_ROOT

%post
# rm -rf /usr/lib/libmatrix-c.so
# ln -s /usr/lib/libmatrix-c.so.%{version} /usr/lib/libmatrix-c.so

%files
# /usr/include/matrix/*.h
# /usr/lib/libmatrix-c.so.%{version}
# /usr/lib/libmatrix-c.so

