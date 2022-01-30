from django.conf.urls import url

from Subs_Mgmt.views import post_data

# include login URLs for the browsable API.
urlpatterns = [

    url('create/(?P<name>[\w\-]+)$', post_data),

]
