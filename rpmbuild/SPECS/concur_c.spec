%define debug_package %{nil}

Name:    concur-c
Version: 1.0.1
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
install -D %_topdir/BUILD/concur-c-%{version}/task.h $RPM_BUILD_ROOT/usr/include/concur/task.h
install -D %_topdir/BUILD/concur-c-%{version}/task_queue.h $RPM_BUILD_ROOT/usr/include/concur/task_queue.h
install -D %_topdir/BUILD/output/libconcur-c.so $RPM_BUILD_ROOT/usr/lib/libconcur-c.so
install -D %_topdir/BUILD/output/libconcur-c.so.%{version} $RPM_BUILD_ROOT/usr/lib/libconcur-c.so.%{version}

%clean
rm -rf $RPM_BUILD_ROOT

%post
rm -rf /usr/lib/libconcur-c.so
ln -s /usr/lib/libconcur-c.so.%{version} /usr/lib/libconcur-c.so

%files
/usr/include/concur/*.h
/usr/lib/libconcur-c.so.%{version}
/usr/lib/libconcur-c.so
